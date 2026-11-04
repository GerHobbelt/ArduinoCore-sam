/*
  main.cpp - Main loop for Arduino sketches
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#define ARDUINO_MAIN
#include "Arduino.h"
#include "wiring.h"

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }


void initUSB() __attribute__((weak));
void initUSB() { 
#if defined(USBCON)
    USBDevice.attach();
#endif
}


/*
 * \brief Main entry point of Arduino application
 */
int main(void) __attribute__((weak));
int main( void )
{
    // Initialize watchdog
    watchdogSetup();

    init();

    initVariant();

    delay(2);   
	// ^^^^^^ the side effect of this call is that it happens to validate/check whether the SysTick interrupt is running properly.
	// If it isn't, this one will hang forever...

    initUSB();
    
    setup();

    for (;;)
    {
        loop();

		yield();
		
        serialEventRun();
    }

    return 0;
}

// Ensure our version of sbrk is used by forcing a reference to it here
// (without this, an undefined reference only occurs later when linking
// newlib, and the dummy from libgloss/nosys will be used instead).
// This variable will be optimized away later.
extern "C" void *_sbrk(int);
void * force_reference_to_sbrk = (void*)&_sbrk;
