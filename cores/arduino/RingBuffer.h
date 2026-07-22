/*
  Copyright (c) 2011 Arduino.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
  See the GNU Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#ifndef _RING_BUFFER_
#define _RING_BUFFER_

#include <stdint.h>
#include <string.h>			// memset, ...

// Define constants and variables for buffering incoming serial data.  We're
// using a ring buffer, in which head is the index of the location
// to which to write the next incoming character and tail is the index of the
// location from which to read.

#define SERIAL_BUFFER_SIZE_DEFAULT   128 // SERIAL_BUFFER_SIZE

class RingBuffer
{
  protected:
    volatile int16_t _iHead;
    volatile int16_t _iTail;
	
  public:
    virtual uint16_t size() const = 0;
	// return (index % size()) :: this method helps prevent using a costly DIV/MOD op 
	// as the virtual methods prevent the compiler from optimizing the classic indexing
	// logic.
    virtual uint16_t wrapIndex(uint16_t index) const = 0;
	virtual volatile uint8_t *buffer() = 0;

  public:
	RingBuffer();

  protected:
	inline bool i__store_char( uint8_t c ) {
	  auto i = (_iHead + 1) % size();

	  // if we should be storing the received character into the location
	  // just before the tail (meaning that the head would advance to the
	  // current location of the tail), we're about to overflow the buffer
	  // and so we don't write the character or advance the head.
	  if ( i != _iTail ) {
	    buffer()[_iHead] = c;
	    _iHead = i;
		return true;
	  }
	  return false;
	}

	inline int i__available( void ) {
	  return wrapIndex(size() + _iHead - _iTail);
	}

	inline int i__peek_char( void )
	{
	  if ( _iHead == _iTail )
	    return -1;

	  return buffer()[_iTail];
	}

	inline int i__read_char( void )
	{
	  // if the head isn't ahead of the tail, we don't have any characters
	  if ( _iHead == _iTail )
	    return -1;

	  uint8_t uc = buffer()[_iTail];
	  _iTail = wrapIndex(_iTail + 1);
	  return uc;
	}

	inline void i__flush( void )
	{
	  while (_iHead != _iTail)
	    ; // Spin locks: wait for transmit data to be sent
	}

	inline void i__drop( void )
	{
	  // clear the buffer i.e. drop all buffered output!
	  _iTail = _iHead;
	}

	inline bool i__isFlushed( void )
	{
	  return _iTail == _iHead;
	}
	
  public:
	bool store_char( uint8_t c ) {
	  // make it an atomic (non-interruptable) operation:
      __disable_irq();
      auto rv = i__store_char(c);
      __enable_irq();
	  return rv;
	}

	int available( void ) {
	  // make it an atomic (non-interruptable) operation:
      __disable_irq();
      auto rv = i__available();
      __enable_irq();
	  return rv;
	}

	int peek_char( void ) {
	  // make it an atomic (non-interruptable) operation:
      __disable_irq();
      auto rv = i__peek_char();
      __enable_irq();
	  return rv;
	}

	int read_char( void ) {
	  // make it an atomic (non-interruptable) operation:
      __disable_irq();
      auto rv = i__read_char();
      __enable_irq();
	  return rv;
	}

	void flush( void ) {
	  // make it an atomic (non-interruptable) operation:
      __disable_irq();
      i__flush();
      __enable_irq();
	}

	void drop( void ) {
	  // make it an atomic (non-interruptable) operation:
      __disable_irq();
      i__drop();
      __enable_irq();
	}

	bool isFlushed( void ) {
	  // make it an atomic (non-interruptable) operation:
      __disable_irq();
      auto rv = i__isFlushed();
      __enable_irq();
	  return rv;
	}
};

template <uint16_t RB_BUFFER_SIZE = SERIAL_BUFFER_SIZE_DEFAULT>
class SizedRingBuffer final : public RingBuffer
{
  protected:
    volatile uint8_t _aucBuffer[RB_BUFFER_SIZE];
	
  public:
    virtual uint16_t size() const override {
	  return RB_BUFFER_SIZE;
	}

	virtual volatile uint8_t *buffer() override {
	  return _aucBuffer;
	}

    virtual uint16_t wrapIndex(uint16_t index) const override {
	  return index % RB_BUFFER_SIZE;
	}

  public:
	SizedRingBuffer() : RingBuffer() {
	  memset((void *)_aucBuffer, 0, sizeof(_aucBuffer));
	}
};

using SmallRingBuffer = SizedRingBuffer<SERIAL_BUFFER_SIZE_DEFAULT>;
using LargeRingBuffer = SizedRingBuffer<1024>;
using TinyRingBuffer  = SizedRingBuffer<64>;

#endif /* _RING_BUFFER_ */
