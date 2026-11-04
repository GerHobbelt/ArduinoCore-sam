
#include "chip.h"
#include "sam.h"

/*
------------------------------------------------------------------------------------------
../../../system/CMSIS/Device/ARM/ARMCM0/Include/ARMCM0.h
../../../system/CMSIS/Device/ARM/ARMCM0/Include/system_ARMCM0.h
../../../system/CMSIS/Device/ARM/ARMCM3/Include/ARMCM3.h
../../../system/CMSIS/Device/ARM/ARMCM3/Include/system_ARMCM3.h
../../../system/CMSIS/Device/ARM/ARMCM4/Include/ARMCM4.h
../../../system/CMSIS/Device/ARM/ARMCM4/Include/system_ARMCM4.h
../../../system/CMSIS/Device/ATMEL/sam.h
../../../system/CMSIS/Device/ATMEL/sam3.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_adc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_dacc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_efc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_pdc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_pio.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_spi.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_supc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_tc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_twi.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_uart.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_usart.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/component/component_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_adc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_dacc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_efc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_pioa.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_piob.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_pioc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_spi.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_supc.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_tc0.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_tc1.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_twi0.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_twi1.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_uart0.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_uart1.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_usart0.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_usart1.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/instance/instance_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n00a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n00b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n0a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n0b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n0c.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n1a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n1b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n1c.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n2a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n2b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n2c.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n4a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n4b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/pio/pio_sam3n4c.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n00a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n00b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n0a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n0b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n0c.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n1a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n1b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n1c.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n2a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n2b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n2c.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n4a.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n4b.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/sam3n4c.h
../../../system/CMSIS/Device/ATMEL/sam3n/include/system_sam3n.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_acc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_adc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_crccu.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_dacc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_efc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_pdc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_pio.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_smc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_spi.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_ssc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_supc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_tc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_twi.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_uart.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_udp.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_usart.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/component/component_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_acc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_adc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_crccu.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_dacc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_efc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_pioa.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_piob.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_pioc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_smc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_spi.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_ssc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_supc.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_tc0.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_tc1.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_twi0.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_twi1.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_uart0.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_uart1.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_udp.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_usart0.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_usart1.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/instance/instance_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s1a.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s1b.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s1c.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s2a.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s2b.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s2c.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s4a.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s4b.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/pio/pio_sam3s4c.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s1a.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s1b.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s1c.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s2a.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s2b.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s2c.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s4a.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s4b.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/sam3s4c.h
../../../system/CMSIS/Device/ATMEL/sam3s/include/system_sam3s.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_acc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_adc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_crccu.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_dacc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_efc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_pdc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_pio.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_smc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_spi.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_ssc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_supc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_tc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_twi.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_uart.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_udp.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_usart.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/component/component_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_acc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_adc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_crccu.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_dacc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_efc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_pioa.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_piob.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_pioc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_smc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_spi.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_ssc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_supc.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_tc0.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_tc1.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_twi0.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_twi1.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_uart0.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_uart1.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_udp.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_usart0.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_usart1.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_usart2.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/instance/instance_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/pio/pio_sam3s8b.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/pio/pio_sam3s8c.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/pio/pio_sam3sd8b.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/pio/pio_sam3sd8c.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/sam3s8b.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/sam3s8c.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/sam3sd8.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/sam3sd8b.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/sam3sd8c.h
../../../system/CMSIS/Device/ATMEL/sam3sd8/include/system_sam3sd8.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_adc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_adc12b.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_dmac.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_efc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_pdc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_pio.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_smc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_spi.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_ssc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_supc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_tc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_twi.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_uart.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_udphs.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_usart.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/component/component_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_adc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_adc12b.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_dmac.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_efc0.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_efc1.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_pioa.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_piob.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_pioc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_smc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_spi.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_ssc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_supc.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_tc0.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_twi0.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_twi1.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_uart.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_udphs.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_usart0.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_usart1.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_usart2.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_usart3.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/instance/instance_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/pio/pio_sam3u1c.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/pio/pio_sam3u1e.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/pio/pio_sam3u2c.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/pio/pio_sam3u2e.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/pio/pio_sam3u4c.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/pio/pio_sam3u4e.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/sam3u.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/sam3u1c.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/sam3u1e.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/sam3u2c.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/sam3u2e.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/sam3u4c.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/sam3u4e.h
../../../system/CMSIS/Device/ATMEL/sam3u/include/system_sam3u.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_adc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_can.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dacc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_dmac.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_efc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_emac.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pdc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pio.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_sdramc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_smc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_spi.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_ssc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_supc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_tc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_trng.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_twi.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uart.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_uotghs.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_usart.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/component/component_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_adc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_can0.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_can1.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_chipid.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_dacc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_dmac.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_efc0.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_efc1.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_emac.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_matrix.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pioa.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_piob.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pioc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_piod.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pioe.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_piof.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pmc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_pwm.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_rstc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_rtc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_rtt.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_sdramc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_smc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_spi0.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_spi1.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_ssc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_supc.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_tc0.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_tc1.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_tc2.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_trng.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_twi0.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_twi1.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_uart.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_uotghs.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_usart0.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_usart1.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_usart2.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_usart3.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/instance/instance_wdt.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3a4c.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3a8c.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x4c.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x4e.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8c.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8e.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/pio/pio_sam3x8h.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/sam3a4c.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/sam3a8c.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/sam3x4c.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/sam3x4e.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8c.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8e.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/sam3x8h.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/sam3xa.h
../../../system/CMSIS/Device/ATMEL/sam3xa/include/system_sam3xa.h
../../../system/CMSIS/Device/ATMEL/sam4.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_acc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_adc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_chipid.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_crccu.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_dacc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_efc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_matrix.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_pdc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_pio.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_pmc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_pwm.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_rstc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_rtc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_rtt.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_smc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_spi.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_ssc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_supc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_tc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_twi.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_uart.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_udp.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_usart.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/component/component_wdt.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_acc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_adc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_chipid.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_crccu.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_dacc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_efc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_gpbr.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_hsmci.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_matrix.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_pioa.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_piob.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_pioc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_pmc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_pwm.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_rstc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_rtc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_rtt.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_smc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_spi.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_ssc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_supc.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_tc0.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_tc1.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_twi0.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_twi1.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_uart0.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_uart1.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_udp.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_usart0.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_usart1.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/instance/instance_wdt.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/pio/pio_sam4s16b.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/pio/pio_sam4s16c.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/pio/pio_sam4s8b.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/pio/pio_sam4s8c.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/sam4s.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/sam4s16b.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/sam4s16c.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/sam4s8b.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/sam4s8c.h
../../../system/CMSIS/Device/ATMEL/sam4s/include/system_sam4s.h
../../../system/CMSIS/Device/_Template_Vendor/Vendor/Device/Include/Device.h
../../../system/CMSIS/Device/_Template_Vendor/Vendor/Device/Include/system_Device.h
------------------------------------------------------------------------------------------
*/

//#define SAM3_SERIES ( SAM3N_SERIES || SAM3S_SERIES || SAM3SD8_SERIES || SAM3U_SERIES || SAM3XA_SERIES )
//#define SAM4_SERIES ( SAM4S_SERIES )


#if 0
#include "../../../system/CMSIS/Device/ARM/ARMCM0/Source/Templates/system_ARMCM0.c"
#include "../../../system/CMSIS/Device/ARM/ARMCM3/Source/Templates/system_ARMCM3.c"
#include "../../../system/CMSIS/Device/ARM/ARMCM4/Source/Templates/system_ARMCM4.c"
#endif

#define LIBCMSIS_GCC_FLAVOUR   1

#if LIBCMSIS_GCC_FLAVOUR == 1

//#define SAM3_SERIES ( SAM3N_SERIES || SAM3S_SERIES || SAM3SD8_SERIES || SAM3U_SERIES || SAM3XA_SERIES )
//#define SAM4_SERIES ( SAM4S_SERIES )
#if SAM3N_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3n/source/as_gcc/startup_sam3n.c"
#elif SAM3S_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3s/source/as_gcc/startup_sam3s.c"
#elfi SAM3SD8_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3sd8/source/as_gcc/startup_sam3sd8.c"
#elif SAM3U_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3u/source/as_gcc/startup_sam3u.c"
#elif SAM3XA_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam3xa/source/as_gcc/startup_sam3xa.c"
#elif SAM4S_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam4s/source/as_gcc/startup_sam4s.c"
#endif

#elif LIBCMSIS_GCC_FLAVOUR == 2

//#define SAM3_SERIES ( SAM3N_SERIES || SAM3S_SERIES || SAM3SD8_SERIES || SAM3U_SERIES || SAM3XA_SERIES )
//#define SAM4_SERIES ( SAM4S_SERIES )
#if SAM3N_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3n/source/gcc/startup_sam3n.c"
#elif SAM3S_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3s/source/gcc/startup_sam3s.c"
#elfi SAM3SD8_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3sd8/source/gcc/startup_sam3sd8.c"
#elif SAM3U_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3u/source/gcc/startup_sam3u.c"
#elif SAM3XA_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam3xa/source/gcc/startup_sam3xa.c"
#elif SAM4S_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam4s/source/gcc/startup_sam4s.c"
#endif

#elif LIBCMSIS_GCC_FLAVOUR == 3

//#define SAM3_SERIES ( SAM3N_SERIES || SAM3S_SERIES || SAM3SD8_SERIES || SAM3U_SERIES || SAM3XA_SERIES )
//#define SAM4_SERIES ( SAM4S_SERIES )
#if SAM3N_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3n/source/gcc_arm/startup_sam3n.c"
#elif SAM3S_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3s/source/gcc_arm/startup_sam3s.c"
#elfi SAM3SD8_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3sd8/source/gcc_arm/startup_sam3sd8.c"
#elif SAM3U_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3u/source/gcc_arm/startup_sam3u.c"
#elif SAM3XA_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam3xa/source/gcc_arm/startup_sam3xa.c"
#elif SAM4S_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam4s/source/gcc_arm/startup_sam4s.c"
#endif

#elif LIBCMSIS_GCC_FLAVOUR == 4

//#define SAM3_SERIES ( SAM3N_SERIES || SAM3S_SERIES || SAM3SD8_SERIES || SAM3U_SERIES || SAM3XA_SERIES )
//#define SAM4_SERIES ( SAM4S_SERIES )
#if SAM3N_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3n/source/gcc_atmel/startup_sam3n.c"
#elif SAM3S_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3s/source/gcc_atmel/startup_sam3s.c"
#elfi SAM3SD8_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3sd8/source/gcc_atmel/startup_sam3sd8.c"
#elif SAM3U_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3u/source/gcc_atmel/startup_sam3u.c"
#elif SAM3XA_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam3xa/source/gcc_atmel/startup_sam3xa.c"
#elif SAM4S_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam4s/source/gcc_atmel/startup_sam4s.c"
#endif

#endif

//#define SAM3_SERIES ( SAM3N_SERIES || SAM3S_SERIES || SAM3SD8_SERIES || SAM3U_SERIES || SAM3XA_SERIES )
//#define SAM4_SERIES ( SAM4S_SERIES )
#if SAM3N_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3n/source/system_sam3n.c"
#elif SAM3S_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3s/source/system_sam3s.c"
#elfi SAM3SD8_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3sd8/source/system_sam3sd8.c"
#elif SAM3U_SERIES 
#include "../../../system/CMSIS/Device/ATMEL/sam3u/source/system_sam3u.c"
#elif SAM3XA_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam3xa/source/system_sam3xa.c"
#elif SAM4S_SERIES
#include "../../../system/CMSIS/Device/ATMEL/sam4s/source/system_sam4s.c"
#endif

#if 0
#include "../../../system/CMSIS/Device/_Template_Vendor/Vendor/Device/Source/Templates/system_Device.c"
#endif
