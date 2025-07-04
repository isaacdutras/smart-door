#ifndef __GPIO_API_H__
#define __GPIO_API_H__

#include "stdint.h"
#include "main.h"
#include "pad_qcx212.h"
#include "gpio_qcx212.h"


#define SWITCH_PAD_ALT_FUNC      PAD_MuxAlt0                                    /**< RedSwitch pin alternate function. */
#define LED_PAD_ALT_FUNC         PAD_MuxAlt0                                    /**< LED pin alternate function. */

/*
----------------------------------------------------  Table 1. GPIO Table. -------------------------------------------------------------
___________________________________________________________________________________________________________________________________________________________________________________________
| Pad ID |       GPIO Number    |  Pin Number  | Instance | Pull (default:options) |       AF0      |      AF1      |    AF2      |      AF3      |  AF4 |   AF5  |   AF6  |      AF7      |
|--------|----------------------|--------------|----------|------------------------|----------------|---------------|-------------|---------------|------|--------|--------|---------------|
|   12   |        GPIO1         |      1       |    0     |      B-PU:nppd         |  GPIO1         |      –	      |  UART2_TXD  |      –        |   –  |    –   |    –   |      –        | 
|   13   |        GPIO2         |      2       |    0     |      B-PU:nppd         |  GPIO2/Timer0  |  UART0_RTSn   |  UART2_RXD  |    SPI1_SSn0  |   –  |  PWM0  |    –   |      –        |
|   14   |        GPIO3         |      3       |    0     |      B-PU:nppd         |  GPIO3         |  UART0_CTSn   |  UART2_TXD  |    SPI1_MOSI  |   –  |  PWM1  |    –   |      –        |
|   15   |        GPIO4         |      4       |    0     |      B-PU:nppd         |  GPIO4         |  UART0_RXD    |  I2C1_SDA   |    SPI1_MISO  |   –  |  PWM2  |    –   |      –        |
|   16   |        GPIO5         |      5       |    0     |      B-PU:nppd         |  GPIO5         |  UART0_TXD    |  I2C1_SCL   |    SPI1_SCLK  |   –  |  PWM3  |    –   |      –        |
|   17   |        GPIO6         |      6       |    0     |      B-PU:nppd         |  GPIO6/Timer1  |  SPI0_SSn0    |  I2C0_SDA   |    UART1_RTSn |   –  |  PWM4  |    –   |      –        |
|   18   |        GPIO7         |      7       |    0     |      B-PU:nppd         |  GPIO7         |  SPI0_MOSI    |  I2C0_SCL   |    UART1_CTSn |   –  |  PWM5  |    –   |      –        |
|   19   |        GPIO13        |      13      |    0     |      B-PU:nppd         |  GPIO13        |  SPI0_MISO    |  I2C1_SDA   |    UART1_RXD  |   –  |  PWM0  |    –   |      –        |
|   20   |        GPIO12        |      12      |    0     |      B-PU:nppd         |  GPIO12        |  SPI0_SCLK    |  I2C1_SCL   |    UART1_TXD  |   –  |  PWM1  |    –   |      –        |
|   25   |        GPIO10        |      10      |    0     |      B-PU:nppd         |  GPIO10/Timer3 |  I2C0_SCL     |      –      |    SPI1_SSn1  |   –  |  PWM0  |    –   |      –        |
|   9    |        SWCLK         |      2       |    1     |      B-PU:nppd         |  SWCLK         |      –        |  UART2_RXD  |    UART1_RTSn |   –  |  PWM4  |    –   |    GPIO18     |
|   10   |        SWDIO         |      3       |    1     |      B-PU:nppd         |  SWDIO         |      –        |  UART2_TXD  |    UART1_CTSn |   –  |  PWM5  |    –   |    GPIO19     |
|   31   |   AON_GPIO0 (GPIO20)	|      4       |    1     |      DIO-PD:nppu       |  GPIO20/Timer5 |      –        |      –      |      –        |   –  |    –   |    –   |      –        |
____________________________________________________________________________________________________________________________________________________________________________________________

-> B  : Bidirectional digital with CMOS input		
-> DIO: Digital input output		
-> NP : pdpu = default no-pull with programmable options following the colon (:)		 
-> PD : nppu = default pull-down with programmable options following the colon (:)		
-> PU : nppd = default pull-up with programmable options following the colon (:)		
*/

/*
PINS DIVISIONS:
BH1750 -> GPIO4 & GPIO5
LED -> GPIO 6
BUZZER -> GPIO 3
RED SWITCH -> GPIO10
*/

typedef enum {
    DEVICE_LED,
    DEVICE_SWITCH,
    DEVICE_BUZZER,
    DEVICE_BH1750
} GpioDevice_t;

//LED INDICATOR
#define LED_INSTANCE 0
#define LED_PIN 6
#define LED_PAD_ID 17
#define LED_MASK (uint32_t)(1 << LED_PIN)

//RED SWITCH
#define SWITCH_INSTANCE 0
#define SWITCH_PIN 10
#define SWITCH_PAD_ID 25
#define SWITCH_MASk (uint32_t)(1 << SWITCH_PIN)

void GPIO_deviceInit(GpioDevice_t);

#endif