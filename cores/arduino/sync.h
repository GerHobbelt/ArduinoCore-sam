
#ifndef _SYNC_H_
#define _SYNC_H_

#include <stdint.h>

#include <sam3.h>           // __disable_irq() et al for Cortex M3 (SAM3 series)

/*
 * Synchronization primitives.
 */

class __Guard {
public:
	__Guard() : 
		enableInterrupts((__get_PRIMASK() & 0x1) == 0 && (__get_FAULTMASK() & 0x1) == 0), 
		loops(1) 
	{
		__disable_irq();
		__DMB();
	}
	~__Guard() {
		if (enableInterrupts) {
			__DMB();
			// http://infocenter.arm.com/help/topic/com.arm.doc.dai0321a/BIHBFEIB.html
			__ISB();
			__enable_irq();
		}
	}
	uint32_t enter() { return loops--; }
private:
	bool enableInterrupts;
	uint16_t loops;
};

#define synchronized for (__Guard __guard; __guard.enter(); )

#endif
