/* ************************************************************************** */
/** 
  @File Name
    sensor_queue.h

  @Summary
 * The interface of the message queue

 */
/* ************************************************************************** */
#ifndef _SENSOR_QUEUE_H


#include "FreeRTOS.h"
#include "queue.h"
#include "app.h"
#include "JSON.h"
#include "timers.h"

typedef enum {MOTOR, COLOR, ARM, INVALIDATE} mode;
//The unit that we want to send to the message queue
typedef struct A_Message {uint8_t val;char units[12]; } AMessage; 
typedef struct TAG_UNION_ {
            mode Mode; 
            uint8_t Motor_Direction; 
            uint8_t Left_Motor_Desired_Speed; 
            uint8_t Right_Motor_Desired_Speed; 
            int Left_Motor_Distance; 
            int Right_Motor_Distance; 
            uint8_t Color_Stuff; 
            uint8_t Arm_Stuff;}TAG_UNION; 
typedef struct block {
    int tag;
    char data[500]; 
    int len;
} Blocks; 

typedef struct cmdQ {
    char *msg;
    int len;
} Commands; 

typedef struct IR_Message {uint8_t val; uint8_t tag;} IR_Message; 
typedef struct Thread_Mss {uint8_t val;} Thread_Mss; 
typedef struct distance_Message {uint8_t val; uint8_t tag;} distance_Message; 
typedef struct US_Message {uint8_t val;} US_Message; 

//#define QUEUE_LENGTH 5
//#define QUEUE_ITEM_SIZE sizeof(AMessage)
#define MOTOR_QUEUE_LENGTH 100
#define MOTOR_QUEUE_ITEM_SIZE sizeof(TAG_UNION)
#define MOTOR_ISR_ITEM_SIZE sizeof(MotorStatus_)
#define SIGNAL_SIZE sizeof(char)
#define UNION_SIZE sizeof(UNION_)
#define UNION_LENGTH 50
#define UART_THREAD_Q_LENGTH 10
#define UART_THREAD_Q_SIZE sizeof(Blocks)
#define ISR_Q_LENGTH 20
#define ISR_Q_SIZE sizeof(Commands)

#define IR_QUEUE_LENGTH 30
#define IR_QUEUE_ITEM_SIZE sizeof(IR_Message)
#define Thread_ISR_QUEUE_LENGTH 20
#define Thread_ISR_QUEUE_ITEM_SIZE sizeof(Thread_Mss)
#define TH_QUEUE_LENGTH 30
#define TH_QUEUE_ITEM_SIZE sizeof(distance_Message)
#define QUEUE_LENGTH 20
#define QUEUE_ITEM_SIZE sizeof(US_Message)



//The message queue handle     
//QueueHandle_t xQueue; 
//QueueHandle_t UART_Queue;
//QueueHandle_t MOTOR_Queue;
//QueueHandle_t MOTOR_ISR_Queue;
//QueueHandle_t SENSOR_ISR_Queue;
//QueueHandle_t BREAK_Queue;
QueueHandle_t UART_TRANSMIT_Queue;
//QueueHandle_t DUMMY_Queue;
//QueueHandle_t DUMMY_Queue2;
QueueHandle_t TRANSMIT_Queue;
QueueHandle_t xQueue2; 
TimerHandle_t xTimers;
QueueHandle_t xQueueISR; 
QueueHandle_t xQueueTh; 
TimerHandle_t xTimerSending;
QueueHandle_t xQueue; 

//QueueHandle_t uart_thread_Q_handle;
//QueueHandle_t ISR_Q_handle;
//Initial the message queue
//QueueHandle_t createMessageQ();
//QueueHandle_t creatUARTMSQ();
//QueueHandle_t creatMOTOR_Queue();
//QueueHandle_t createMOTOR_ISR_Queue();
//QueueHandle_t createSENSOR_ISR_Queue();
//QueueHandle_t createBreak_Queue();
QueueHandle_t createUART_TRANSMIT_Queue();
//QueueHandle_t createDUMMY_Queue();
//QueueHandle_t createDUMMY_Queue2();
QueueHandle_t createTransmit_Queue();

QueueHandle_t createMessageQIR();   
QueueHandle_t createMessageQISR();
QueueHandle_t createMessageQThread();
QueueHandle_t createMessageQ();

//QueueHandle_t create_MQ_uart_thread();
//QueueHandle_t create_MQ_ISR();
//This function will send data to the message queue
//@param pvItemToQueue The unit we send to the queue
//@param pxHigherPriorityTaskWoken Check if any task is woken when the data is send to the queue
//BaseType_t SendMessageFromISR(const void *pvItemToQueue,  BaseType_t pxHigherPriorityTaskWoken);
//    
//BaseType_t SendUARTMessageFromISR(char *pvItemToQueue, BaseType_t pxHigherPriorityTaskWoken);
//
//BaseType_t SendMotorMessage(const void *pvItemToQueue);
//
//BaseType_t SendMotor_ISR_Message(const void *pvItemToQueue);
//
//BaseType_t SendSensor_ISR_MessageFromISR(const void *pvItemToQueue, BaseType_t pxHigherPriorityTaskWoken);
//
//BaseType_t SendBreak_MessageFromISR(const void *pvItemToQueue, BaseType_t pxHigherPriorityTaskWoken);

BaseType_t SendUART_TRANSMIT_Message(const void *pvItemToQueue);
//
//BaseType_t SendDUMMY_MessageFromISR(const void *pvItemToQueue, BaseType_t pxHigherPriorityTaskWoken);
//
//BaseType_t SendDUMMY_MessageFromISR2(const void *pvItemToQueue, BaseType_t pxHigherPriorityTaskWoken);

BaseType_t SendTransmit_Message(const void *pvItemToQueue);

//BaseType_t MQ_send_from_ISR(const void *pvItemToQueue,  BaseType_t pxHigherPriorityTaskWoken);
//
//BaseType_t MQ_send_from_callback(const void *pvItemToQueue);

//This function will receive data from the message queue
//@param message The data received
//BaseType_t ReceiveMessage(AMessage *message);
//
//BaseType_t ReceiveUARTMessage(char *message);    
//
//BaseType_t ReceiveMotorMessage(TAG_UNION *message);    
//
//BaseType_t ReceiveMotor_ISR_Message(MotorStatus_ *message,BaseType_t pxHigherPriorityTaskWoken); 
//
//BaseType_t ReceiveSensor_ISR_Message(MotorStatus_ *message); 
//
//BaseType_t ReceiveBreak_Message(char *message);

BaseType_t ReceiveUART_TRANSMIT_Message(char *message,BaseType_t pxHigherPriorityTaskWoken);

//BaseType_t ReceiveDUMMY_Message(char *message);
//
//BaseType_t ReceiveDUMMY_Message2(char *message);

BaseType_t ReceiveTransmit_Message(UNION_ *message);

//BaseType_t MQ_send_from_ISR(const void *pvItemToQueue,  BaseType_t pxHigherPriorityTaskWoken);
//
//BaseType_t MQ_recv_in_ISR(Commands *cmd, BaseType_t TaskWokenByReceive);

bool SendMessageFromTimer(const void *pvItemToQueue);
bool ReceiveMessageIR(IR_Message *message);
bool SendMessageFromThread(const void *pvItemToQueue);
bool ReceiveMessageISR(Thread_Mss *message,  BaseType_t pxHigherPriorityTaskWoken);
bool SendMessageFromUS(const void *pvItemToQueue);
bool SendMessageFromSendingTimer(const void *pvItemToQueue);
bool ReceiveMessageUS(distance_Message *message);
bool SendMessageFromISR(const void *pvItemToQueue,  BaseType_t *pxHigherPriorityTaskWoken);
bool ReceiveMessage(US_Message *message);
#endif
     


