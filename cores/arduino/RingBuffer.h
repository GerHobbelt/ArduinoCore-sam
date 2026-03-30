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

// Define constants and variables for buffering incoming serial data.  We're
// using a ring buffer, in which head is the index of the location
// to which to write the next incoming character and tail is the index of the
// location from which to read.

#define SERIAL_BUFFER_SIZE_DEFAULT   128 // SERIAL_BUFFER_SIZE

template <uint16_t RB_BUFFER_SIZE = SERIAL_BUFFER_SIZE_DEFAULT>
class RingBuffer
{
  public:
    volatile uint8_t _aucBuffer[RB_BUFFER_SIZE];
    volatile int16_t _iHead ;
    volatile int16_t _iTail ;
	
    constexpr const uint32_t _size = RB_BUFFER_SIZE;

  public:
    RingBuffer( void ) ;
    void store_char( uint8_t c ) ;
} ;

#endif /* _RING_BUFFER_ */
