#include "th_ISR_queue.h"

//This function will create a message queue 
//QueueHandle_t createMessageQISR() {
//    return xQueueCreate( Thread_ISR_QUEUE_LENGTH, Thread_ISR_QUEUE_ITEM_SIZE ); 
//}
//
////This function will send data to the message queue
//bool SendMessageFromThread(const void *pvItemToQueue){
//    BaseType_t TH_Queue_Send_Status;
//    TH_Queue_Send_Status = xQueueSendToBack(xQueueISR, pvItemToQueue, (TickType_t)10);
//    if (TH_Queue_Send_Status == pdTRUE){
//        return true;
//    }
//    else{
//        return false;
//    }         
//}
//
////This function will receive data from the message queue
//bool ReceiveMessageISR(Thread_Mss *message, BaseType_t pxHigherPriorityTaskWoken) {
//    BaseType_t ISR_Queue_Receive_Status;
//    ISR_Queue_Receive_Status = xQueueReceiveFromISR(xQueueISR, message, &pxHigherPriorityTaskWoken);
//    if ( ISR_Queue_Receive_Status == pdTRUE){
//        return true;
//    }
//    else{
//        return false;
//    }       
//}