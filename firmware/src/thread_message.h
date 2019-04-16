/* ************************************************************************** */
/** 
  @File Name
    sensor_queue.h

  @Summary
 * The interface of the message queue

 */
/* ************************************************************************** */
#ifndef _SENSOR_QUEUE_H


//#include "FreeRTOS.h"
//#include "queue.h"
//#include "app.h"
//#include "timers.h"
//
////The unit that we want to send to the message queue
//typedef struct distance_Message {uint8_t val; uint8_t tag;} distance_Message; 
//     
//#define TH_QUEUE_LENGTH 30
//#define TH_QUEUE_ITEM_SIZE sizeof(distance_Message)
//     
////The message queue handle     
//QueueHandle_t xQueueTh; 
//TimerHandle_t xTimerSending;
//
////Initial the message queue
//QueueHandle_t createMessageQThread();
//     
////This function will send data to the message queue
////@param pvItemToQueue The unit we send to the queue
////@param pxHigherPriorityTaskWoken Check if any task is woken when the data is send to the queue
//bool SendMessageFromUS(const void *pvItemToQueue);
//bool SendMessageFromSendingTimer(const void *pvItemToQueue);
////This function will receive data from the message queue
////@param message The data received
//bool ReceiveMessageUS(distance_Message *message);
//         
#endif