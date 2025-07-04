#include "GPIO_Api.h"
#include "string.h"
#include "bsp.h"
#include "ostask.h"
#include "debug_log.h"
#include "FreeRTOS.h"
#include "main.h"


/**
  \fn          static void appInit(void *arg)
  \brief
  \return
*/

extern USART_HandleTypeDef huart1;

static void luck(void *arg)
{
    bool ledState = false;
    while (1)
    {
      printf("Hello World\n");
      GPIO_PinWrite(LED_INSTANCE, 1 << LED_PIN, (ledState ? 1 << LED_PIN : 0));
      ledState = !ledState;
      vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void appInit(void *arg)
{
    GPIO_deviceInit(DEVICE_LED);
    GPIO_deviceInit(DEVICE_SWITCH);
    slpManNormalIOVoltSet(IOVOLT_3_30V);

    uint32_t uart_cntrl = (ARM_USART_MODE_ASYNCHRONOUS | ARM_USART_DATA_BITS_8 | ARM_USART_PARITY_NONE |
                         ARM_USART_STOP_BITS_1 | ARM_USART_FLOW_CONTROL_NONE);
    
    HAL_USART_InitPrint(&huart1, GPR_UART1ClkSel_26M, uart_cntrl, 115200);

    xTaskCreate(luck, "Luck", 124, NULL, 2, NULL);

    return;
}

/**
  \fn          int main_entry(void)
  \brief       main entry function.
  \return
*/
void main_entry(void)
{ 
    
    BSP_CommonInit();
   
    osKernelInitialize();
    registerAppEntry(appInit, NULL);
    if (osKernelGetState() == osKernelReady)
    {
        osKernelStart();
    }
    while(1);
}
