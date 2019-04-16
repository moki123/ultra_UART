#include "ir_queue.h"

//This function will create a message queue 
//QueueHandle_t createMessageQIR() {
//    return xQueueCreate( IR_QUEUE_LENGTH, IR_QUEUE_ITEM_SIZE ); 
//}
//
////This function will send data to the message queue
//bool SendMessageFromTimer(const void *pvItemToQueue){
//    BaseType_t Timer_Queue_Send_Status;
//    Timer_Queue_Send_Status = xQueueSendToBack(xQueue2, pvItemToQueue, portMAX_DELAY);
//    if (Timer_Queue_Send_Status == pdTRUE){
//        return true;
//    }
//    else{
//        return false;
//    } 
//}
//
////This function will receive data from the message queue
//bool ReceiveMessageIR(IR_Message *message) {
//    BaseType_t Queue_Receive_Status;
//    Queue_Receive_Status = xQueueReceive( xQueue2, message, portMAX_DELAY );
//    if (Queue_Receive_Status == pdPASS){
//        return true;
//    }
//    else{
//        return false;
//    }       
//}