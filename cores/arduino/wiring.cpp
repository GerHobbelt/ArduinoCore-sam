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

#include "Arduino.h"

#include <sync.h>           // synchronized macro, ...

#ifdef __cplusplus
extern "C" {
#endif

uint32_t millis( void )
{
    // todo: ensure no interrupts
    uint32_t t = GetTickCount();
    t /= SYSTICK_MS_TO_TICKS(1);
    return t;
}

// Interrupt-compatible version of micros
// Theory: repeatedly take readings of SysTick counter, millis counter and SysTick interrupt pending flag.
// When it appears that millis counter and pending is stable and SysTick hasn't rolled over, use these
// values to calculate micros. If there is a pending SysTick, add one to the millis counter in the calculation.
#if 0
uint32_t micros( void )
{
    uint32_t ticks, ticks2;
    uint32_t pend, pend2;
    uint32_t count, count2;

    ticks2  = SysTick->VAL;
    pend2   = !!((SCB->ICSR & SCB_ICSR_PENDSTSET_Msk) || (SCB->SHCSR & SCB_SHCSR_SYSTICKACT_Msk));
    count2  = GetTickCount();

    do {
        ticks = ticks2;
        pend = pend2;
        count = count2;
        ticks2  = SysTick->VAL;
        pend2   = !!((SCB->ICSR & SCB_ICSR_PENDSTSET_Msk) || (SCB->SHCSR & SCB_SHCSR_SYSTICKACT_Msk));
        count2  = GetTickCount();
    } while ((pend != pend2) || (count != count2) || (ticks2 < ticks));

    return ((count2 + pend2) * SYSTICK_USECS_PER_TICK) + (SysTick->LOAD + 1 - ticks2) / (SystemCoreClock / 1000000);
}
#else
uint32_t micros( void )
{
    uint32_t ticks;
    uint32_t pend;
    uint32_t count;

    synchronized {
        ticks = SysTick->VAL;
        pend  = !!((SCB->ICSR & SCB_ICSR_PENDSTSET_Msk) || (SCB->SHCSR & SCB_SHCSR_SYSTICKACT_Msk));
        count = GetTickCount();
    }
    
    return (count + pend) * SYSTICK_USECS_PER_TICK + (SysTick->LOAD + 1 - ticks) / (SystemCoreClock / 1000000);
}
#endif

// original function:
// uint32_t micros( void )
// {
//     uint32_t ticks ;
//     uint32_t count ;
//
//     SysTick->CTRL;
//     do {
//         ticks = SysTick->VAL;
//         count = GetTickCount();
//     } while (SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk);
//
//     return count * 1000000 / SYSTICK_FREQUENCY + (SysTick->LOAD + 1 - ticks) / (SystemCoreClock/1000000) ;
// }


void delay( uint32_t ms )
{
    if (ms == 0) {
        return;
    }
    ms *= SYSTICK_MS_TO_TICKS(1);
    uint32_t start = GetTickCount();
    do {
        yield();
    } while (GetTickCount() - start < ms);
}

#if defined ( __ICCARM__ ) /* IAR Ewarm 5.41+ */
extern signed int putchar( signed int c ) ;
/**
 * \brief
 *
 * \param c  Character to output.
 *
 * \return The character that was output.
 */
extern WEAK signed int putchar( signed int c )
{
    return c ;
}
#endif /* __ICCARM__ */

#ifdef __cplusplus
}
#endif
