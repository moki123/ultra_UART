/*******************************************************************************
 System Interrupts File

  File Name:
    system_interrupt.c

  Summary:
    Raw ISR definitions.

  Description:
    This file contains a definitions of the raw ISRs required to support the
    interrupt sub-system.

  Summary:
    This file contains source code for the interrupt vector functions in the
    system.

  Description:
    This file contains source code for the interrupt vector functions in the
    system.  It implements the system and part specific vector "stub" functions
    from which the individual "Tasks" functions are called for any modules
    executing interrupt-driven in the MPLAB Harmony system.

  Remarks:
    This file requires access to the systemObjects global data structure that
    contains the object handles to all MPLAB Harmony module objects executing
    interrupt-driven in the system.  These handles are passed into the individual
    module "Tasks" functions to identify the instance of the module to maintain.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2011-2014 released Microchip Technology Inc.  All rights reserved.

Microchip licenses to you the right to use, modify, copy and distribute
Software only when embedded on a Microchip microcontroller or digital signal
controller that is integrated into your product or third party product
(pursuant to the sublicense terms in the accompanying license agreement).

You should refer to the license agreement accompanying this Software for
additional information regarding your rights and obligations.

SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT WARRANTY OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT LIMITATION, ANY WARRANTY OF
MERCHANTABILITY, TITLE, NON-INFRINGEMENT AND FITNESS FOR A PARTICULAR PURPOSE.
IN NO EVENT SHALL MICROCHIP OR ITS LICENSORS BE LIABLE OR OBLIGATED UNDER
CONTRACT, NEGLIGENCE, STRICT LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR
OTHER LEGAL EQUITABLE THEORY ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES
INCLUDING BUT NOT LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT, PUNITIVE OR
CONSEQUENTIAL DAMAGES, LOST PROFITS OR LOST DATA, COST OF PROCUREMENT OF
SUBSTITUTE GOODS, TECHNOLOGY, SERVICES, OR ANY CLAIMS BY THIRD PARTIES
(INCLUDING BUT NOT LIMITED TO ANY DEFENSE THEREOF), OR OTHER SIMILAR COSTS.
 *******************************************************************************/
// DOM-IGNORE-END

// *****************************************************************************
// *****************************************************************************
// Section: Included Files
// *****************************************************************************
// *****************************************************************************

#include "system/common/sys_common.h"
#include "app.h"
#include "system_definitions.h"
#include "debug.h"
#include "LUT_US.h"
#include "sensor_queue.h"
#include "LUT_ir.h"

// *****************************************************************************
// *****************************************************************************
// Section: System Interrupt Vector Functions
// *****************************************************************************
// *****************************************************************************
void IntHandlerDrvUsartInstance0(void)
{
    BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
    if(SYS_INT_SourceStatusGet(INT_SOURCE_USART_1_TRANSMIT)){
        
        static char message[1024];
        static length = 0;
        static txState = 0;
        if(txState == 0){
            ReceiveUART_TRANSMIT_Message(message,pxHigherPriorityTaskWoken);
            txState = 1;
        }
        else if(txState == 1){
            if (length < strlen(message)){
                while (PLIB_USART_TransmitterBufferIsFull(USART_ID_1))
                {

                }
                PLIB_USART_TransmitterByteSend(USART_ID_1, message[length]);
                length++;
                
            }
            else if(length == strlen(message)){
                length = 0;
                txState = 0;
                memset(message,0,sizeof(message));
                SYS_INT_SourceDisable(INT_SOURCE_USART_1_TRANSMIT);
            }
            
            
        }
        
        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_TRANSMIT);

        
 } 
    if(PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_RECEIVE))
    {      
        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_RECEIVE); 
    }
    if(PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_USART_1_ERROR))
    {
        PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_USART_1_ERROR);
    }
    portEND_SWITCHING_ISR(pxHigherPriorityTaskWoken);

}

 void IntHandlerDrvUsartInstance1(void)
{
    static int count = 0;
    static uint8_t distance = 0;
    struct US_Message ultra_message;
    if (SYS_INT_SourceStatusGet(INT_SOURCE_USART_2_RECEIVE)){
        if(PLIB_USART_ReceiverDataIsAvailable(USART_ID_2)){
            uint8_t result = PLIB_USART_ReceiverByteReceive(USART_ID_2);
            SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_RECEIVE);
            if (result == 82){
                count =0;
                distance = 0;
            }
            if(count == 1){
                distance = 100 *lut[result];
            }else if(count == 2){
                distance = distance + 10 * lut[result];
            }else if(count == 3){
                distance = distance + lut[result];
                ultra_message.val = distance;
                BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
                dbgOutputLoc(ISR_SEND_MESSAGE_TO_US_QUEUE_START);
                bool status = SendMessageFromISR(&ultra_message, &pxHigherPriorityTaskWoken);
                dbgOutputLoc(ISR_SEND_MESSAGE_TO_US_QUEUE_DONE);
                portEND_SWITCHING_ISR(pxHigherPriorityTaskWoken);     
            }else{
                count = 0;
            }
            count ++;   
        }
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_2_RECEIVE);
    }
}

void IntHandlerDrvUsartInstance2(void)
{
    DRV_USART_TasksTransmit(sysObj.drvUsart2);
    DRV_USART_TasksError(sysObj.drvUsart2);
    DRV_USART_TasksReceive(sysObj.drvUsart2);
}

void IntHandlerDrvUsartInstance3(void)
{
    static int count = 0;
    static uint8_t distance = 0;
    struct US_Message ultra_message;
    if (SYS_INT_SourceStatusGet(INT_SOURCE_USART_4_RECEIVE)){
        if(PLIB_USART_ReceiverDataIsAvailable(USART_ID_4)){
            uint8_t result = PLIB_USART_ReceiverByteReceive(USART_ID_4);
            SYS_INT_SourceStatusClear(INT_SOURCE_USART_4_RECEIVE);
            if (result == 82){
                count =0;
                distance = 0;
            }
            if(count == 1){
                distance = 100 *lut[result];
            }else if(count == 2){
                distance = distance + 10 * lut[result];
            }else if(count == 3){
                distance = distance + lut[result];
                ultra_message.val = distance;
                BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
                dbgOutputLoc(ISR_SEND_MESSAGE_TO_US_QUEUE_START);
                bool status = SendMessageFromISR(&ultra_message, &pxHigherPriorityTaskWoken);
                dbgOutputLoc(ISR_SEND_MESSAGE_TO_US_QUEUE_DONE);
                portEND_SWITCHING_ISR(pxHigherPriorityTaskWoken);     
            }else{
                count = 0;
            }
            count ++;   
        }
        SYS_INT_SourceStatusClear(INT_SOURCE_USART_4_RECEIVE);
    }
}
 
void IntHandlerDrvAdc(void)
{
   uint16_t adc = 0;
//   PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3); 
//   PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
   int i;
   if (PLIB_INT_SourceFlagGet(INT_ID_0, INT_SOURCE_ADC_1)){
       for(i=0;i<16;i++){
            adc += PLIB_ADC_ResultGetByIndex(ADC_ID_1, i);
       }
   }
   struct IR_Message message2;
   uint8_t temp = adc >> 8;
   message2.val = temp;
   message2.tag = 0x11;
   BaseType_t pxHigherPriorityTaskWoken = pdFALSE;
   bool status = SendMessageFromADCISR(&message2, &pxHigherPriorityTaskWoken);
   portEND_SWITCHING_ISR(pxHigherPriorityTaskWoken); 
   /* Clear ADC Interrupt Flag */
   PLIB_INT_SourceFlagClear(INT_ID_0, INT_SOURCE_ADC_1);
   
}

void IntHandlerDrvTmrInstance0(void)
{
    PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_TIMER_2);
}

void IntHandlerDrvTmrInstance1(void)
{
    PLIB_INT_SourceFlagClear(INT_ID_0,INT_SOURCE_TIMER_3);
}


 /*******************************************************************************
 End of File
*/
