/*******************************************************************************
  MPLAB Harmony Application Source File
  
  Company:
    Microchip Technology Inc.
  
  File Name:
    ir.c

  Summary:
    This file contains the source code for the MPLAB Harmony application.

  Description:
    This file contains the source code for the MPLAB Harmony application.  It 
    implements the logic of the application's state machine and it may call 
    API routines of other MPLAB Harmony modules in the system, such as drivers,
    system services, and middleware.  However, it does not call any of the
    system interfaces (such as the "Initialize" and "Tasks" functions) of any of
    the modules in the system or make any assumptions about when those functions
    are called.  That is the responsibility of the configuration-specific system
    files.
 *******************************************************************************/

// DOM-IGNORE-BEGIN
/*******************************************************************************
Copyright (c) 2013-2014 released Microchip Technology Inc.  All rights reserved.

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

#include "ir.h"
//#include "ultra_queue.h"
//#include "ir_queue.h"
#include "debug.h"
//#include "thread_message.h"
#include "LUT_ir.h"
#include "sensor_queue.h"

// *****************************************************************************
// *****************************************************************************
// Section: Global Data Definitions
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Application Data

  Summary:
    Holds application data

  Description:
    This structure holds the application's data.

  Remarks:
    This structure should be initialized by the APP_Initialize function.
    
    Application strings and buffers are be defined outside this structure.
*/

IR_DATA irData;

// *****************************************************************************
// *****************************************************************************
// Section: Application Callback Functions
// *****************************************************************************
// *****************************************************************************

/* TODO:  Add any necessary callback functions.
*/

// *****************************************************************************
// *****************************************************************************
// Section: Application Local Functions
// *****************************************************************************
// *****************************************************************************


/* TODO:  Add any necessary local functions.
*/
void vTimerCallback( TimerHandle_t xTimer )
 {
    struct IR_Message message2;
    message2.val= 0x11;
    message2.tag = 0x33;
    bool sendStatus = SendMessageFromTimer(&message2);
 }

// *****************************************************************************
// *****************************************************************************
// Section: Application Initialization and State Machine Functions
// *****************************************************************************
// *****************************************************************************

/*******************************************************************************
  Function:
    void IR_Initialize ( void )

  Remarks:
    See prototype in ir.h.
 */

void IR_Initialize ( void )
{
    DRV_ADC_Open();
    DRV_ADC_Start();
    xTimers = xTimerCreate("Timer", pdMS_TO_TICKS(100), pdTRUE, 0, vTimerCallback);
}


/******************************************************************************
  Function:
    void IR_Tasks ( void )

  Remarks:
    See prototype in ir.h.
 */

void IR_Tasks ( void )
{
    xTimerStart(xTimers, 0);
    while(1){
        
        dbgOutputLoc(ENTERING_IR_TASK);
        struct IR_Message message2;
        struct distance_Message th_message;
        dbgOutputLoc(TASK_RECEIVE_FROM_IR_QUEUE_START);
        bool IRstatus = ReceiveMessageIR(&message2);// top
        dbgOutputLoc(TASK_RECEIVE_FROM_IR_QUEUE_DONE);
        static uint8_t ir_data;
        switch(message2.tag)
        {
            case 0x11:
                ir_data = message2.val;
                break;
            case 0x33:
                th_message.val = lut_IR[ir_data];
                th_message.tag = 0x44;
                bool thread_send_status =  SendMessageFromUS(&th_message);
                break;
        }
    }
}

 

/*******************************************************************************
 End of File
 */
