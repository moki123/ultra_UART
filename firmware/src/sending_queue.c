#include "sending_queue.h"

//This function will create a message queue 
QueueHandle_t createMessageQSending() {
    return xQueueCreate( Sending_QUEUE_LENGTH, Sending_QUEUE_ITEM_SIZE ); 
}

//This function will send data to the message queue
bool SendMessageFromTimerSending(const void *pvItemToQueue){
    BaseType_t Timer_Queue_Send_Status;
    Timer_Queue_Send_Status = xQueueSendToBack(Sending_Message, pvItemToQueue, portMAX_DELAY);
    if (Timer_Queue_Send_Status == pdTRUE){
        return true;
    }
    else{
        return false;
    } 
}

//This function will receive data from the message queue
bool ReceiveMessageSending(Sending_Message *message) {
    BaseType_t Queue_Receive_Status;
    Queue_Receive_Status = xQueueReceive( Sending_Message, message, portMAX_DELAY );
    if (Queue_Receive_Status == pdPASS){
        return true;
    }
    else{
        return false;
    }       
}
