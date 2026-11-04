
#ifndef _SYNC_H_
#define _SYNC_H_

#include <stdint.h>

#include "chip.h"           // __disable_irq() et al for Cortex M3 (SAM3 series)

/*
 * Synchronization primitives.
 */

class __Guard {
public:
	__Guard() : 
		flags(cpu_irq_save()), 
		loops(1) 
	{
	}
	~__Guard() {
		cpu_irq_restore(flags);
	}
	uint32_t enter() { 
		return loops--; 
	}
private:
	irqflags_t flags;
	uint16_t loops;
};

// synchronization / 'atomic operation' macro.
//
// To be used like this:
//
//     synchronized {
//       ...
//       // this scope block contains the desired 'atomic operation'.
//       // using `return` statement in here is allowed.
//       ...
//     }
//
#define synchronized for (__Guard __guard; __guard.enter(); )

class LockEP
{
public:
    LockEP(uint32_t ep __attribute__ ((unused))) : flags(cpu_irq_save())
    {
    }
    ~LockEP()
    {
        cpu_irq_restore(flags);
    }
private:
    irqflags_t flags;
};

#endif
