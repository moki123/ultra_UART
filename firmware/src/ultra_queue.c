#include "ultra_queue.h"

//This function will create a message queue 
//QueueHandle_t createMessageQ() {
//    return xQueueCreate( QUEUE_LENGTH, QUEUE_ITEM_SIZE ); 
//}
//
////This function will send data to the message queue
//bool SendMessageFromISR(const void *pvItemToQueue,  BaseType_t *pxHigherPriorityTaskWoken) {
//    BaseType_t ISR_Queue_Send_Status;
//    ISR_Queue_Send_Status = xQueueSendFromISR(xQueue, pvItemToQueue, pxHigherPriorityTaskWoken);
//    if (ISR_Queue_Send_Status == pdTRUE){
//        return true;
//    }
//    else{
//        return false;
//    }       
//}
//
////This function will receive data from the message queue
//bool ReceiveMessage(US_Message *message) {
//    BaseType_t Queue_Receive_Status;
//    Queue_Receive_Status = xQueueReceive( xQueue, message, portMAX_DELAY );
//    if (Queue_Receive_Status == pdPASS){
//        return true;
//    }
//    else{
//        return false;
//    }       
//}