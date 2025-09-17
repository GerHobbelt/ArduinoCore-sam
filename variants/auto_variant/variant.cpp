/*
  Copyright (c) 2014-2015 Arduino LLC.  All right reserved.

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


#include "variant.h"
#include "Arduino.h"

/*
 * Pins descriptions
 */
const PinDescription g_APinDescription[] = {
/*
 +------------+------------------+--------+-----------------+--------+-----------------------+---------+---------+--------+--------+----------+----------+
 | Pin number | Board Function   |  PIN   | Notes           | Peri.A |     Peripheral B      | Perip.C | Perip.D | Peri.E | Peri.F | Periph.G | Periph.H |
 |            |                  |        |                 |   EIC  | ADC |  AC | PTC | DAC | SERCOMx | SERCOMx |  TCCx  |  TCCx  |    COM   | AC/GLCK  |
 |            |                  |        |                 |(EXTINT)|(AIN)|(AIN)|     |     | (x/PAD) | (x/PAD) | (x/WO) | (x/WO) |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | DAC/Analog       |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 0          | A0/DAC           |  PA02  | DAC Output      |   02   | *00 |     | Y00 | OUT |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | Isolated Inputs  |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 1          | ISO_7            |  PB08  | Isolated In 7   |   08   | *02 |     | Y14 |     |         |  *4/00  |  TC4/0 |        |          |          |
 | 2          | ISO_8            |  PB09  | Isolated In 8   |  *09   | *03 |     | Y15 |     |         |  *4/01  |* TC4/1 |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | Digital I/O      |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 3          | D4               |  PA04  | Digital I/O     |   04   | *04 |  00 | Y02 |     |         |   0/00  |*TCC0/0 |        |          |          |
 | 4          | D5               |  PA05  | Digital I/O     |   05   | *05 |  01 | Y03 |     |         |   0/01  |*TCC0/1 |        |          |          |
 | 5          | D6               |  PA06  | Digital I/O     |   06   | *06 |  02 | Y04 |     |         |   0/02  | TCC1/0 |        |          |          |
 | 6          | D7               |  PA07  | Digital I/O     |   07   | *07 |  03 | Y05 |     |         |   0/03  |*TCC1/1 |        | I2S/SD0  |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | I2C Interface    |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 7          | SDA              |  PA08  | I2C Data        |   NMI  |  16 |     | X00 |     |  *0/00  |   2/00  | TCC0/0 | TCC1/2 | I2S/SD1  |          |
 | 8          | SCL              |  PA09  | I2C Clock       |   09   | *17 |     | X01 |     |  *0/01  |   2/01  | TCC0/1 | TCC1/3 | I2S/MCK0 |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | Analog Inputs    |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 9          | A3               |  PA10  | Analog Input    |   10   | *18 |     | X02 |     |   0/02  |   2/02  | TCC1/0 |*TCC0/2 | I2S/SCK0 | GCLK_IO4 |
 | 10         | A2               |  PA11  | Analog Input    |   11   | *19 |     | X03 |     |   0/03  |   2/03  | TCC1/1 |*TCC0/3 | I2S/FS0  | GCLK_IO5 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | Isolated Inputs  |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 11         | ISO_1            |  PB10  | Isolated In 1   |  *10   |     |     |     |     |         |   4/02  |* TC5/0 | TCC0/4 | I2S/MCK1 | GCLK_IO4 |
 | 12         | ISO_2            |  PB11  | Isolated In 2   |  *11   |     |     |     |     |         |   4/03  |* TC5/1 | TCC0/5 | I2S/SCK1 | GCLK_IO5 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | I2C1 Interface   |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 13         | SDA1             |  PA12  | I2C1 Data       |   12   |     |     |     |     |  *2/00  |   4/00  | TCC2/0 | TCC0/6 |          | AC/CMP0  |
 | 14         | SCL1             |  PA13  | I2C1 Clock      |   13   |     |     |     |     |  *2/01  |   4/01  | TCC2/1 | TCC0/7 |          | AC/CMP1  |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | Unused           |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 15         | -                |  PA14  | Unused          |   14   |     |     |     |     |   2/02  |   4/02  |  TC3/0 | TCC0/4 |          | GCLK_IO0 |
 | 16         | -                |  PA15  | Unused          |   15   |     |     |     |     |  *2/03  |   4/03  |  TC3/1 | TCC0/5 |          | GCLK_IO1 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | SPI Ethernet     |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 17         | SPI_MISO         |  PA16  | SPI MISO        |  *00   |     |     | X04 |     |  *1/00  |   3/00  |*TCC2/0 | TCC0/6 |          | GCLK_IO2 |
 | 18         | SPI_SCK          |  PA17  | SPI Clock       |   01   |     |     | X05 |     |  *1/01  |   3/01  | TCC2/1 | TCC0/7 |          | GCLK_IO3 |
 | 19         | SPI_SS           |  PA18  | SPI Select      |   02   |     |     | X06 |     |   1/02  |   3/02  |  TC3/0 | TCC0/2 |          | AC/CMP0  |
 | 20         | SPI_MOSI         |  PA19  | SPI MOSI        |   03   |     |     | X07 |     |  *1/03  |   3/03  |* TC3/1 | TCC0/3 | I2S/SD0  | AC/CMP0  |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | SPI1 LoRa        |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 21         | SPI1_MISO        |  PA20  | SPI1 MISO       |  *04   |     |     | X08 |     |   5/02  |  *3/02  |  TC7/0 |*TCC0/6 |          | GCLK_IO4 |
 | 22         | SPI1_RST         |  PA21  | SPI1 Reset      |  *05   |     |     | X09 |     |   5/03  |  *3/02  |  TC7/1 |*TCC0/7 | I2S/FS0  | GCLK_IO5 |
 | 23         | SPI1_MOSI        |  PA22  | SPI1 MOSI       |  *06   |     |     | X10 |     |  *3/00  |   5/00  |* TC4/0 | TCC0/4 |          | GCLK_IO6 |
 | 24         | SPI1_SCK         |  PA23  | SPI1 Clock      |  *07   |     |     | X11 |     |  *3/01  |   5/01  |* TC4/1 | TCC0/5 | USB/SOF  | GCLK_IO7 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | USB              |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 25         | USB_DM           |  PA24  | USB D-          |   12   |     |     |     |     |   3/02  |   5/02  |  TC5/0 | TCC1/2 | USB/DM   |          |
 | 26         | USB_DP           |  PA25  | USB D+          |   13   |     |     |     |     |   3/03  |   5/03  |  TC5/1 | TCC1/3 | USB/DP   |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | RS485            |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 27         | RS485_TX         |  PB22  | RS485 TX        |   06   |     |     |     |     |         |  *5/02  |  TC7/0 |        |          | GCLK_IO0 |
 | 28         | RS485_RX         |  PB23  | RS485 RX        |   07   |     |     |     |     |         |  *5/03  |  TC7/1 |        |          | GCLK_IO1 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | System           |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 29         | LED              |  PA27  | Status LED      |  *15   |     |     |     |     |         |         |        |        |          | GCLK_IO0 |
 | 30         | NV               |  PA28  | Non-volatile    |   08   |     |     |     |     |         |         |        |        |          | GCLK_IO0 |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 |            | Sync             |        |                 |        |     |     |     |     |         |         |        |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 | 31         | SYNC1            |  PB02  | Sync Output 1   |  *02   | *10 |     | Y08 |     |         |   5/00  |  TC6/0 |        |          |          |
 | 32         | SYNC2            |  PB03  | Sync Output 2   |  *03   | *11 |     | Y09 |     |         |   5/01  |  TC6/1 |        |          |          |
 +------------+------------------+--------+-----------------+--------+-----+-----+-----+-----+---------+---------+--------+--------+----------+----------+
 */
  // 0 - Not connected
  { PORTA,  2, PIO_ANALOG,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG /*DAC*/         ), ADC_Channel0,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

  // 1/2 Isolated input 7 and 8
  { PORTB,  8, PIO_SERCOM_ALT,  (PIN_ATTR_DIGITAL|PIN_ATTR_ANALOG             ), ADC_Channel2,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // TX:   SERCOM4/PAD[2]
  { PORTB,  9, PIO_SERCOM_ALT,  (PIN_ATTR_PWM|PIN_ATTR_TIMER                  ), ADC_Channel3,   PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_9    }, // RX:   SERCOM4/PAD[2]

  // 3..10 Digital
  { PORTA,  4, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel4,   PWM0_CH0,   TCC0_CH0,     EXTERNAL_INT_NONE },
  { PORTA,  5, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel5,   PWM0_CH1,   TCC0_CH1,     EXTERNAL_INT_NONE },
  { PORTA,  6, PIO_DIGITAL,  (PIN_ATTR_DIGITAL                                ), ADC_Channel6,   NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },
  { PORTA,  7, PIO_DIGITAL,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), ADC_Channel7,   PWM1_CH1,   TCC1_CH1,     EXTERNAL_INT_NONE }, 
  { PORTA,  8, PIO_SERCOM,   (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SDA: SERCOM0/PAD[0]
  { PORTA,  9, PIO_SERCOM,   (PIN_ATTR_DIGITAL                                ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCL: SERCOM0/PAD[1]
  { PORTA, 10, PIO_ANALOG,   (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), ADC_Channel18,  PWM0_CH2,   TCC0_CH2,     EXTERNAL_INT_NONE },
  { PORTA, 11, PIO_ANALOG,   (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), ADC_Channel19,  PWM0_CH3,   TCC0_CH3,     EXTERNAL_INT_NONE },

  // 11..16 Isolated inputs 1..6
  { PORTB, 10, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER     ), No_ADC_Channel, PWM5_CH0,   TC5_CH0,      EXTERNAL_INT_10   },
  { PORTB, 11, PIO_DIGITAL, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER     ), No_ADC_Channel, PWM5_CH1,   TC5_CH1,      EXTERNAL_INT_11   },
  { PORTA, 12, PIO_SERCOM, (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SDA1: SERCOM2/PAD[0]
  { PORTA, 13, PIO_SERCOM, (PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SCL1: SERCOM2/PAD[1] 
  { PORTA, 14, PIO_DIGITAL, (PIN_ATTR_NONE                                    ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 
  { PORTA, 15, PIO_DIGITAL, (PIN_ATTR_NONE                                    ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, 

  // 17..20 SPI
  { PORTA, 16, PIO_SERCOM,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER     ), No_ADC_Channel, PWM2_CH0,   TCC2_CH0,     EXTERNAL_INT_0    }, // MISO: SERCOM1/PAD[0]
  { PORTA, 17, PIO_SERCOM,  (PIN_ATTR_DIGITAL                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_1    }, // SCK:  SERCOM1/PAD[1]
  { PORTA, 18, PIO_DIGITAL, (PIN_ATTR_DIGITAL                                 ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // SS:   SERCOM1/PAD[2]
  { PORTA, 19, PIO_SERCOM,  (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER     ), No_ADC_Channel, PWM3_CH1,   TC3_CH1,      EXTERNAL_INT_NONE }, // MOSI: SERCOM1/PAD[3]

  // 21..24 SPI1
  { PORTA, 20, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, PWM0_CH6,   TCC0_CH6,     EXTERNAL_INT_4  }, // MISO: SERCOM3/PAD[2]
  { PORTA, 21, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER_ALT), No_ADC_Channel, PWM0_CH7,   TCC0_CH7,     EXTERNAL_INT_5  }, // RST:  SERCOM3/PAD[3]
  { PORTA, 22, PIO_SERCOM,     (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM4_CH0,   TC4_CH0,      EXTERNAL_INT_6  }, // MOSI: SERCOM3/PAD[0]
  { PORTA, 23, PIO_SERCOM,     (PIN_ATTR_DIGITAL|PIN_ATTR_PWM|PIN_ATTR_TIMER    ), No_ADC_Channel, PWM4_CH1,   TC4_CH1,      EXTERNAL_INT_7  }, // SCK:  SERCOM3/PAD[1]

  // 25/26 USB
  { PORTA, 24, PIO_COM, PIN_ATTR_NONE                                          , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DM
  { PORTA, 25, PIO_COM, PIN_ATTR_NONE                                          , No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // USB/DP

  // 27/28 - RS485
  { PORTB, 22, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL                              ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // TX:   SERCOM5/PAD[2]
  { PORTB, 23, PIO_SERCOM_ALT, (PIN_ATTR_DIGITAL                              ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE }, // RX:   SERCOM5/PAD[3]

  // 29 - LED
  { PORTA, 27, PIO_DIGITAL,(PIN_ATTR_NONE                                     ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_15   },

  // 30 NV
  { PORTA, 28, PIO_DIGITAL,(PIN_ATTR_DIGITAL                                  ), No_ADC_Channel, NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_NONE },

  // 31/32 - Sync Pins
  { PORTB,  2, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                 ), ADC_Channel10,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_2    },
  { PORTB,  3, PIO_ANALOG,  (PIN_ATTR_DIGITAL                                 ), ADC_Channel11,  NOT_ON_PWM, NOT_ON_TIMER, EXTERNAL_INT_3    },

} ;

extern "C" {
    unsigned int PINCOUNT_fn() {
        return (sizeof(g_APinDescription) / sizeof(g_APinDescription[0]));
    }
}

const void* g_apTCInstances[TCC_INST_NUM+TC_INST_NUM]={ TCC0, TCC1, TCC2, TC3, TC4, TC5 } ;

void initVariant() {
  // NINA - SPI boot
  //pinMode(NINA_GPIO0, OUTPUT);
  //digitalWrite(NINA_GPIO0, HIGH);

  // disable NINA
  //pinMode(NINA_RESETN, OUTPUT);
  //digitalWrite(NINA_RESETN, LOW);
}

// Multi-serial objects instantiation
SERCOM sercom0( SERCOM0 ) ;
SERCOM sercom1( SERCOM1 ) ;
SERCOM sercom2( SERCOM2 ) ;
SERCOM sercom3( SERCOM3 ) ;
SERCOM sercom4( SERCOM4 ) ;
SERCOM sercom5( SERCOM5 ) ;

Uart Serial1( &sercom5, PIN_SERIAL1_RX, PIN_SERIAL1_TX, PAD_SERIAL1_RX, PAD_SERIAL1_TX ) ;
Uart Serial2( &sercom4, PIN_SERIAL2_RX, PIN_SERIAL2_TX, PAD_SERIAL2_RX, PAD_SERIAL2_TX ) ;

void SERCOM4_Handler()
{
  Serial2.IrqHandler();
}

void SERCOM5_Handler()
{
  Serial1.IrqHandler();
}
