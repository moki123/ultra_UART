#include "app.h"
#include "stdio.h"
#include "debug.h"
#include "Distance.h"
#include "sensor_queue.h"

void vTimerCallbackSending( TimerHandle_t xTimerSending )
 {
    
    struct distance_Message th_message;
    th_message.val = 100;
    th_message.tag = 0x66;
    bool sendStatus = SendMessageFromUS(&th_message);
 }

void APP_Initialize ( void )
{
    PLIB_USART_ReceiverIdleStateLowEnable(USART_ID_2);
    xTimerSending = xTimerCreate("Sending Timer", pdMS_TO_TICKS(200), pdTRUE, 0, vTimerCallbackSending);
}


void APP_Tasks ( void )
{
    static int condition=0;
    static uint8_t ultra_output;
    static uint8_t ir_output;
    uint8_t output = 0;
    static int sending = 0;
    xTimerStart(xTimerSending, 0);
    static int count = 0;
    int result = 0;
    while(1){
        
        dbgOutputLoc(ENTERING_APP_TASK);
        distance_Message th_message;
        dbgOutputLoc(TASK_RECEIVE_FROM_APP_QUEUE_START);
        bool status = ReceiveMessageUS(&th_message);
        dbgOutputLoc(TASK_RECEIVE_FROM_APP_QUEUE_DONE);
        switch(th_message.tag)
        {
            case 0x22:
                ultra_output = th_message.val;
                break;
            case 0x44:
                ir_output = th_message.val;
                break;
            case 0x66:
                if (ultra_output == 5){
                    output = ir_output;
                }else{
                    output = ultra_output;
                }
                
                if (output <= 100){
                    result = 1;
                }else{
                    result = 0;
                    output = 0;
                }
                sendRequest3(Sensor,0, 0, 0, 0, output, 0, result);
                PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3); 
                PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
                break;
        }
        dbgOutputLoc(LEAVING_APP_TASK);
    }
    
}
/*******************************************************************************
 End of File
 */
