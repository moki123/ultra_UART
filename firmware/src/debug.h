#ifndef DEBUG_H
#include <stdbool.h>
#include "app.h"




    /* ************************************************************************** */
    /* ************************************************************************** */
    /* Section: Constants                                                         */
    /* ************************************************************************** */
    /* ************************************************************************** */

    /*  A brief description of a section can be given directly below the section
        banner.
     */


    /* ************************************************************************** */
    /** Descriptive Constant Name
      @Summary
        Brief one-line summary of the constant.
      @Description
        Full description, explaining the purpose and usage of the constant.
        <p>
        Additional description in consecutive paragraphs separated by HTML 
        paragraph breaks, as necessary.
        <p>
        Type "JavaDoc" in the "How Do I?" IDE toolbar for more information on tags.
      @Remarks
        Any additional remarks
     */
#define ENTERING_DISTANCE_TASK 0x00   
#define LEAVING_DISTANCE_TASK 0x01
#define TASK_RECEIVE_FROM_US_QUEUE_START 0x02
#define TASK_RECEIVE_FROM_US_QUEUE_DONE 0x03

#define ENTERING_IR_TASK 0x10  
#define LEAVING_IR_TASK 0x11
#define TASK_RECEIVE_FROM_IR_QUEUE_START 0x12
#define TASK_RECEIVE_FROM_IR_QUEUE_DONE 0x13

#define ENTERING_APP_TASK 0x20  
#define LEAVING_APP_TASK 0x21
#define TASK_RECEIVE_FROM_APP_QUEUE_START 0x22
#define TASK_RECEIVE_FROM_APP_QUEUE_DONE 0x23

#define ENTERING_US_ISR 0x04
#define LEAVING_US_ISR 0x05
#define ENTERING_IR_ISR 0x14
#define LEAVING_IR_ISR 0x15

#define ISR_SEND_MESSAGE_TO_US_QUEUE_START 0x06
#define ISR_SEND_MESSAGE_TO_US_QUEUE_DONE 0x07
#define ISR_SEND_MESSAGE_TO_IR_QUEUE_START 0x16
#define ISR_SEND_MESSAGE_TO_IR_QUEUE_DONE 0x17
#define DIS_SEND_MESSAGE_TO_APP_QUEUE_START 0x26
#define DIS_SEND_MESSAGE_TO_APP_QUEUE_DONE 0x27
#define IR_SEND_MESSAGE_TO_APP_QUEUE_START 0x28
#define IR_SEND_MESSAGE_TO_APP_QUEUE_DONE 0x29

#define STOP_CODE_TRUE true
#define STOP_CODE_FALSE false
#define STOP_CODE 0x40
#define US_QUEUE_FULL 0x41
#define US_QUEUE_EMPTY 0x42
#define IR_QUEUE_FULL 0x43
#define IR_QUEUE_EMPTY 0x44


    // *****************************************************************************
    // *****************************************************************************
    // Section: Interface Functions
    // *****************************************************************************
    // *****************************************************************************

    /*  A brief description of a section can be given directly below the section
        banner.
     */

    // *****************************************************************************
    /** 
    @Function
      void dbgOutputVal(unsigned int outVal) 
    @Summary
      The value of outVal must be <= 127. This routine must verify this.
    @Remarks
      Refer to the example_file.h interface header for function usage details.
   */
    void dbgOutputVal(unsigned int outVal);
    
    /** 
    @Function
      void dbgUARTVal(unsigned char outVal) 
    @Summary
      This value will be written to the UART.
    @Remarks
      Refer to the example_file.h interface header for function usage details.
   */
    void dbgUARTVal(const char *str);
    
    /** 
    @Function
      dbgOutputLoc(unsigned int outVal)
    @Summary
      The value of outVal must be <= 127. This routine must verify this.
    @Remarks
      Refer to the example_file.h interface header for function usage details.
   */
    void dbgOutputLoc(unsigned int outVal);

    /** 
    @Function
      dbgStopCode(unsigned int outVal)
    @Summary
      This debug routine is called when all code stop. It will also output an unique value if that happens
    @Remarks
      Refer to the example_file.h interface header for function usage details.
   */
    void dbgStopCode(bool status, unsigned int loc); 
    
    void UARTSendString(const char* str);
    
    void dbgUARTVal2(char *outVal);

#endif