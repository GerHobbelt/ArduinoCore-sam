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

/**
  * \file syscalls_sam3.c
  *
  * Implementation of newlib syscall.
  *
  */

/*----------------------------------------------------------------------------
 *        Headers
 *----------------------------------------------------------------------------*/


#include "syscalls.h"

#include <stdio.h>
#include <stdarg.h>
#include <errno.h>

#include "sam.h"
#include "Reset.h"
#include "variant.h"        // `Serial` instance declaration

#if defined (  __GNUC__  ) /* GCC CS3 */
  #include <sys/types.h>
  #include <sys/stat.h>
#endif

// Helper macro to mark unused parameters and prevent compiler warnings.
// Appends _UNUSED to the variable name to prevent accidentally using them.
#ifdef __GNUC__
#  define UNUSED(x) x ## _UNUSED __attribute__((__unused__))
#else
#  define UNUSED(x) x ## _UNUSED
#endif

extern "C" {

/*----------------------------------------------------------------------------
 *        Exported variables
 *----------------------------------------------------------------------------*/

#undef errno
extern int errno ;

/*----------------------------------------------------------------------------
 *        Exported functions
 *----------------------------------------------------------------------------*/
extern void _exit( int status ) ;
extern void _kill( int pid, int sig ) ;
extern int _getpid ( void ) ;

const uint8_t *sbrk_heap_end = NULL;

__attribute((weak)) extern caddr_t _sbrk(int incr)
{
  const uint8_t *prev_heap_end;

  if (sbrk_heap_end == NULL) {
      sbrk_heap_end = (const uint8_t *)&_end;
  }
  prev_heap_end = sbrk_heap_end;

  sbrk_heap_end += incr;

  //
  // rudimentary protection against running the heap expansion into the stack at the end of the RAM space...
  // ...of course this DOES NOT protect against memory corruption due to the stack growing down more than
  // was anticipated at build time, so it MAY be useful to replace this sbrk() with a memory-scanning/monitoring
  // replacement which is better able to protect against that particular scenario by monitoring the actually-used
  // (worst case!) stack space at the time of its invocation.
  //
  const uint8_t * const stack_start = (const uint8_t *)&_sstack;
  if (sbrk_heap_end >= stack_start) {
#if 0
    __set_errno(ENOMEM);
#else
    errno = ENOMEM;
#endif
    return (caddr_t) -1;
  }

  return (caddr_t)prev_heap_end;
}

__attribute((weak)) extern int link( UNUSED(const char *cOld), UNUSED(const char *cNew) )
{
    return -1 ;
}

__attribute((weak)) extern int _close( UNUSED(int file) )
{
#if 0               // too aggressive: we haven't checked `file` so we better keep the `Serial` active/open after this `close()`!
    Serial.end();
#else
    Serial.flush();
#endif
    
    return 0;
}

__attribute((weak)) extern int _fstat( UNUSED(int file), struct stat *st )
{
    st->st_mode = S_IFCHR ;

    return 0 ;
}

__attribute((weak)) extern int _isatty( UNUSED(int file) )
{
    return 1 ;
}

__attribute((weak)) extern int _lseek( UNUSED(int file), UNUSED(int ptr), UNUSED(int dir) )
{
    return 0 ;
}

__attribute((weak)) extern int _read(UNUSED(int file), char *ptr, int len )
{
	// TODO: check `file` handle so we only do this for STDIN?
	
    return Serial.read(ptr, len);
}

__attribute((weak)) extern int _write( UNUSED(int file), char *ptr, int len )
{
#if 0
    int iIndex ;

//    for ( ; *ptr != 0 ; ptr++ )
    for ( iIndex = 0 ; iIndex < len ; iIndex++, ptr++ )
    {
//        UART_PutChar( *ptr ) ;

		// Check if the transmitter is ready
		  while ((UART->UART_SR & UART_SR_TXRDY) != UART_SR_TXRDY)
			;

		  // Send character
		  UART->UART_THR = *ptr;
    }

    return iIndex ;
#else
	// TODO: check `file` handle so we only do this for STDOUT/STDERR?
	
    return Serial.write(ptr, len);
#endif    
}

extern void _exit( int status )
{
#if 0
    // printf is probably not set up by Arduino, and shouldn't be used.
    printf( "Exiting with status %d.\n", status ) ;
#else
	// To get rid of compiler warning 
	( void ) status; 
#endif
	
    initiateReset(5000);
    
    for ( ; ; ) ;
}

extern void _kill( UNUSED(int pid), UNUSED(int sig) )
{
    return ;
}

__attribute((weak)) extern int _getpid ( void )
{
    return -1 ;
}

} // extern "C" 
