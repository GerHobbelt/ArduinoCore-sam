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


void setupBrownout() {
	/* Disable the brown-out detector during configuration,
	   otherwise it might misbehave and reset the
	   microcontroller. */
	SYSCTRL->BOD33.bit.ENABLE = 0;
	while (!SYSCTRL->PCLKSR.bit.B33SRDY) 
		;
	/* Configure the brown-out detector so that the
	   program can use it to watch the power supply
	   voltage */
	SYSCTRL->BOD33.reg = (
		/* This sets the minimum voltage level to 3.0v - 3.2v.
		   See datasheet table 37-21. */
		SYSCTRL_BOD33_LEVEL(48) |
		/* Since the program is waiting for the voltage to rise,
		   don't reset the microcontroller if the voltage is too
		   low. */
		SYSCTRL_BOD33_ACTION_NONE |
		/* Enable hysteresis to better deal with noisy power
		   supplies and voltage transients. */
		SYSCTRL_BOD33_HYST
	);

	/* Enable the brown-out detector and then wait for
	   the voltage level to settle. */
	SYSCTRL->BOD33.bit.ENABLE = 1;
	while (!SYSCTRL->PCLKSR.bit.BOD33RDY) 
		;

	/* BOD33DET is set when the voltage is *too low*,
	   so wait for it to be cleared. */
	while (SYSCTRL->PCLKSR.bit.BOD33DET) 
		;
}


/*
 * \brief Main entry point of Arduino application
 */
int main(void) __attribute__((weak));
int main( void )
{
    // Initialize watchdog
    watchdogSetup();

    setupBrownout();

    init();

    initVariant();

    delay(2);   
	// ^^^^^^ the side effect of this call is that it happens to validate/check whether the SysTick interrupt is running properly.
	// If it isn't, this one will hang forever...

    initUSB();
    
	/* Let the brown-out detector automatically reset the microcontroller
	if the voltage drops too low. */
	SYSCTRL->BOD33.bit.ENABLE = 0;
	while (!SYSCTRL->PCLKSR.bit.B33SRDY) 
		;
	SYSCTRL->BOD33.reg |= SYSCTRL_BOD33_ACTION_RESET;
	SYSCTRL->BOD33.bit.ENABLE = 1;

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
