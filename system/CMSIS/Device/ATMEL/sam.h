/* ----------------------------------------------------------------------------
 *         SAM Software Package License
 * ----------------------------------------------------------------------------
 * Copyright (c) 2012, Atmel Corporation
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

#ifndef _SAM_INCLUDED_
#define _SAM_INCLUDED_

// unsupported way of writing these, since GCC 3/4: 
//
// #define part_is_defined(part) (defined(__ ## part ## __))
//
// --> warning: this use of "defined" may not be portable [-Wexpansion-to-defined]

/*
 * ----------------------------------------------------------------------------
 * SAM3 family
 * ----------------------------------------------------------------------------
 */

/* SAM3N series */
#if ( \
    defined( __SAM3N00A__ ) || \
    defined( __SAM3N00B__ ) )
#define SAM3N00 1
#else
#define SAM3N00 0
#endif

#if ( \
    defined( __SAM3N0A__ ) || \
    defined( __SAM3N0B__ ) || \
    defined( __SAM3N0C__ ) )
#define SAM3N0 1
#else
#define SAM3N0 0
#endif

#if ( \
    defined( __SAM3N1A__ ) || \
    defined( __SAM3N1B__ ) || \
    defined( __SAM3N1C__ ) )
#define SAM3N1 1
#else
#define SAM3N1 0
#endif

#if ( \
    defined( __SAM3N2A__ ) || \
    defined( __SAM3N2B__ ) || \
    defined( __SAM3N2C__ ) )
#define SAM3N2 1
#else
#define SAM3N2 0
#endif

#if ( \
    defined( __SAM3N4A__ ) || \
    defined( __SAM3N4B__ ) || \
    defined( __SAM3N4C__ ) )
#define SAM3N4 1
#else
#define SAM3N4 0
#endif

/* Entire SAM3N series */
#define SAM3N_SERIES (SAM3N00 || SAM3N0 || SAM3N1 || SAM3N2 || SAM3N4)


/* SAM3S series */
#if ( \
    defined( __SAM3S00A__ ) || \
    defined( __SAM3S00B__ ) )
#define SAM3S00 1
#else
#define SAM3S00 0
#endif

#if ( \
    defined( __SAM3S0A__ ) || \
    defined( __SAM3S0B__ ) || \
    defined( __SAM3S0C__ ) )
#define SAM3S0 1
#else
#define SAM3S0 0
#endif

#if ( \
    defined( __SAM3S1A__ ) || \
    defined( __SAM3S1B__ ) || \
    defined( __SAM3S1C__ ) )
#define SAM3S1 1
#else
#define SAM3S1 0
#endif

#if ( \
    defined( __SAM3S2A__ ) || \
    defined( __SAM3S2B__ ) || \
    defined( __SAM3S2C__ ) )
#define SAM3S2 1
#else
#define SAM3S2 0
#endif

#if ( \
    defined( __SAM3S4A__ ) || \
    defined( __SAM3S4B__ ) || \
    defined( __SAM3S4C__ ) )
#define SAM3S4 1
#else
#define SAM3S4 0
#endif

/* Entire SAM3S series */
#define SAM3S_SERIES (SAM3S00 || SAM3S0 ||SAM3S1 || SAM3S2 || SAM3S4)

/* SAM3SD8 series */
#if ( \
    defined( __SAM3S8B__ ) || \
    defined( __SAM3S8C__ ) )
#define SAM3S8 1
#else
#define SAM3S8 0
#endif

#if ( \
    defined( __SAM3SD8B__ ) || \
    defined( __SAM3SD8C__ ) )
#define SAM3SD8 1
#else
#define SAM3SD8 0
#endif

/* Entire SAM3SD8 series */
#define SAM3SD8_SERIES (SAM3S8 || SAM3SD8)

/* SAM3U series */
#if ( \
    defined( __SAM3U1C__ ) || \
    defined( __SAM3U1E__ ) )
#define SAM3U1 1
#else
#define SAM3U1 0
#endif

#if ( \
    defined( __SAM3U2C__ ) || \
    defined( __SAM3U2E__ ) )
#define SAM3U2 1
#else
#define SAM3U2 0
#endif

#if ( \
    defined( __SAM3U4C__ ) || \
    defined( __SAM3U4E__ ) )
#define SAM3U4 1
#else
#define SAM3U4 0
#endif

/* Entire SAM3U series */
#define SAM3U_SERIES (SAM3U1 || SAM3U2 || SAM3U4)

/* SAM3XA series */
#if ( \
    defined( __SAM3X4C__ ) || \
    defined( __SAM3X4E__ ) )
#define SAM3X4 1
#else
#define SAM3X4 0
#endif

#if ( \
    defined( __SAM3X8C__ ) || \
    defined( __SAM3X8E__ ) || \
    defined( __SAM3X8H__ ) )
#define SAM3X8 1
#else
#define SAM3X8 0
#endif

#if ( \
    defined( __SAM3A4C__ ) )
#define SAM3A4 1
#else
#define SAM3A4 0
#endif

#if ( \
    defined( __SAM3A8C__ ) )
#define SAM3A8 1
#else
#define SAM3A8 0
#endif

/* Entire SAM3XA series */
#define SAM3XA_SERIES ( SAM3X4 || SAM3X8 || SAM3A4 || SAM3A8)

/*
 * ----------------------------------------------------------------------------
 * SAM4 family
 * ----------------------------------------------------------------------------
 */


/* Entire SAM3 Family */
#define SAM3_SERIES ( SAM3N_SERIES || SAM3S_SERIES || SAM3SD8_SERIES || SAM3U_SERIES || SAM3XA_SERIES )

/* SAM4S series */
#if ( \
    defined( __SAM4S8B__ ) || \
    defined( __SAM4S8C__ ) )
#define SAM4S8 1
#else
#define SAM4S8 0
#endif

#if ( \
    defined( __SAM4S16B__ ) || \
    defined( __SAM4S16C__ ) )
#define SAM4S16 1
#else
#define SAM4S16 0
#endif

/* Entire SAM4S series */
#define SAM4S_SERIES ( SAM4S8 || SAM4S16)

/* Entire SAM4 Family */
#define SAM4_SERIES ( SAM4S_SERIES )

/*
 * ----------------------------------------------------------------------------
 * SAM9 family
 * ----------------------------------------------------------------------------
 */

/*
 * ----------------------------------------------------------------------------
 * SAM7 family
 * ----------------------------------------------------------------------------
 */



/*
 * ----------------------------------------------------------------------------
 * Whole SAM product line
 * ----------------------------------------------------------------------------
 */
#define SAM ( SAM3_SERIES || SAM4_SERIES )

/*
 * ----------------------------------------------------------------------------
 * Header inclusion
 * ----------------------------------------------------------------------------
 */

#if SAM3_SERIES
#include "sam3.h"
#endif /* SAM3 */

#if SAM4_SERIES
#include "sam4.h"
#endif /* SAM4 */

#endif /* _SAM_INCLUDED_ */
