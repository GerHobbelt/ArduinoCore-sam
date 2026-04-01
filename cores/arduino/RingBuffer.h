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
  public:
    volatile int16_t _iHead;
    volatile int16_t _iTail;
	
    virtual uint16_t size() const = 0;
	// return (index % size()) :: this method helps prevent using a costly DIV/MOD op 
	// as the virtual methods prevent the compiler from optimizing the classic indexing
	// logic.
    virtual uint16_t wrapIndex(uint16_t index) const = 0;
	virtual volatile uint8_t *buffer() = 0;

  public:
	RingBuffer();

	virtual void store_char( uint8_t c ) = 0;
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

	virtual void store_char( uint8_t c ) override {
	  int i = (uint32_t)(_iHead + 1) % size();

	  // if we should be storing the received character into the location
	  // just before the tail (meaning that the head would advance to the
	  // current location of the tail), we're about to overflow the buffer
	  // and so we don't write the character or advance the head.
	  if ( i != _iTail )
	  {
	    buffer()[_iHead] = c;
	    _iHead = i;
	  }
	}

  public:
	SizedRingBuffer() : RingBuffer() {
	  memset((void *)_aucBuffer, 0, sizeof(_aucBuffer));
	}
};

using SmallRingBuffer = SizedRingBuffer<SERIAL_BUFFER_SIZE_DEFAULT>;
using LargeRingBuffer = SizedRingBuffer<1024>;

#endif /* _RING_BUFFER_ */
