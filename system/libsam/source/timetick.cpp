/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2011-2012, Atmel Corporation
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following condition is met:
 *
 * - Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the disclaimer below.
 *
 * Atmel's name may not be used to endorse or promote products derived from
 * this software without specific prior written permission.
 *
 * DISCLAIMER: THIS SOFTWARE IS PROVIDED BY ATMEL "AS IS" AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE
 * DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
 * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * ----------------------------------------------------------------------------
 */

/**
 *  \file
 *  Implement simple system tick usage.
 */

/*----------------------------------------------------------------------------
 *         Headers
 *----------------------------------------------------------------------------*/

#include "../chip.h"

#include "variant.h"

// hacky fix for https://web.archive.org/web/20260108152405/https://gcc.gnu.org/bugzilla/show_bug.cgi?id=83271: extern
extern WEAK const uint8_t SystemCoreTickFreqMultiplier = 1; // = 1 (or higher); an application setting which will only be set once, so can be stored in ROM

/*----------------------------------------------------------------------------
 *         Local variables
 *----------------------------------------------------------------------------*/

/** Tick Counter incremented every (1000 / SYSTICK_FREQUENCY) ms */
static volatile uint32_t _dwTickCount = 0;

/*----------------------------------------------------------------------------
 *         Exported Functions
 *----------------------------------------------------------------------------*/

/**
 *  \brief Handler for Sytem Tick interrupt.
 */
extern void TimeTick_Increment( void )
{
    _dwTickCount = _dwTickCount + 1;
}

/**
 *  \brief Configures the SAM3 SysTick & reset tickCount.
 *  Systick interrupt handler will generate an interrupt every (1000 / SYSTICK_FREQUENCY) ms and increase a
 *  tickCount.
 *  \param dwNew_MCK  Current master clock.
 */
extern uint32_t TimeTick_Configure( uint32_t dwNew_MCK )
{
    _dwTickCount = 0;

    SysTick_Config( dwNew_MCK / SYSTICK_FREQUENCY );

#if 0
    {
      uint32_t load2 = SysTick->LOAD;

      Serial.printf("TimeTick LOAD.1 = %u @ %u / %u / %u\n", load2, SystemCoreClock, SYSTICK_FREQUENCY, dwNew_MCK / SYSTICK_FREQUENCY);
    }
#endif
    
    SysTick_Config( SystemCoreClock / SYSTICK_FREQUENCY );
    
#if 0
    {
      uint32_t load2 = SysTick->LOAD;

      Serial.printf("TimeTick LOAD.2 = %u @ %u / %u / %u\n", load2, SystemCoreClock, SYSTICK_FREQUENCY, SystemCoreClock / SYSTICK_FREQUENCY);
    }
#endif
    
    return 0;
}

/**
 *  \brief Get current Tick Count, in (1000 / SYSTICK_FREQUENCY) ms.
 */
extern uint32_t GetTickCount( void )
{
    return _dwTickCount;
}

/**
 *  \brief Sync Wait for several ms
 */
extern void Wait( uint32_t dwMs )
{
    uint32_t dwStart ;
    uint32_t dwCurrent ;

	dwMs *= SYSTICK_MS_TO_TICKS(1);
	
    dwStart = GetTickCount();
    do
    {
		yield();
		
        dwCurrent = GetTickCount();
    } while ( dwCurrent - dwStart < dwMs );
}

/**
 *  \brief Sync Sleep for several ms
 */
extern void Sleep( uint32_t dwMs )
{
    uint32_t dwStart ;
    uint32_t dwCurrent ;

	dwMs *= SYSTICK_MS_TO_TICKS(1);
	
    dwStart = GetTickCount();

    for(;;)
    {
		yield();
		
        dwCurrent = GetTickCount();

        if ( dwCurrent - dwStart >= dwMs )
        {
            break;
        }

        __WFI();
    }
}

