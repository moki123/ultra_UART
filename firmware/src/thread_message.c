#include "thread_message.h"

//This function will create a message queue 
//QueueHandle_t createMessageQThread() {
//    return xQueueCreate( TH_QUEUE_LENGTH, TH_QUEUE_ITEM_SIZE ); 
//}
//
////This function will send data to the message queue
//bool SendMessageFromUS(const void *pvItemToQueue) {
//    BaseType_t TH_Queue_Send_Status;
//    TH_Queue_Send_Status = xQueueSendToBack(xQueueTh, pvItemToQueue, (portMAX_DELAY));
//    if (TH_Queue_Send_Status == pdTRUE){
//        return true;
//    }
//    else{
//        return false;
//    }       
//}
//
////This function will receive data from the message queue
//bool ReceiveMessageUS(distance_Message *message) {
//    BaseType_t Queue_Receive_Status;
//    Queue_Receive_Status = xQueueReceive( xQueueTh, message, portMAX_DELAY );
//    if (Queue_Receive_Status == pdPASS){
//        return true;
//    }
//    else{
//        return false;
//    }       
//}