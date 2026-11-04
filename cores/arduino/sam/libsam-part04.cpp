
#include "chip.h"
#include "sam.h"

//#include "../../../system/libsam/include/pio_it.h"

#include "../../../system/libsam/include/udp.h"
#include "../../../system/libsam/include/udphs.h"


// fix warning: using value of assignment with 'volatile'-qualified left operand is deprecated [-Wvolatile]
//#define Clr_bits(lvalue, mask)  ((lvalue) &= ~(mask))
#undef Clr_bits
template<typename VolaDst_t, typename Src_t>
void Clr_bits(VolaDst_t &lvalue, const Src_t mask) {
  lvalue = lvalue & ~(mask);
}


template<typename T1, typename T2>
auto min(T1 a, T2 b) -> decltype(a > b ? b : a) {
  if (a > b)
	  return b;
  return a;
}

template<typename T1, typename T2>
auto max(T1 a, T2 b) -> decltype(a > b ? a : b) {
  if (a > b)
	  return a;
  return b;
}


#if (SAM3XA_SERIES) || (SAM3N_SERIES) || (SAM3S_SERIES)
#include "../../../system/libsam/source/dacc.c"
#endif // (SAM3XA_SERIES) || (SAM3N_SERIES) || (SAM3S_SERIES)

#if (SAM3XA_SERIES)
#include "../../../system/libsam/source/can.c"
#include "../../../system/libsam/source/emac.c"
#include "../../../system/libsam/source/trng.c"
#include "../../../system/libsam/source/uotghs_device.c"
#include "../../../system/libsam/source/uotghs_host.c"
#endif /* (SAM3XA_SERIES) */

