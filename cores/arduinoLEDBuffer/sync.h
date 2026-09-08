
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
		__disable_irq();
		__DMB();
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

#define synchronized for (__Guard __guard; __guard.enter(); )

#endif
