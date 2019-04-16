/* ************************************************************************** */
/** Descriptive File Name
  @Company
    Company Name
  @File Name
    filename.c
  @Summary
    Brief description of the file.
  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */

/* This section lists the other files that are included in this file.
 */

/* TODO:  Include other files here if needed. */
#include "debug.h"


/* ************************************************************************** */
/* ************************************************************************** */
// Section: Interface Functions                                               */
/* ************************************************************************** */
/* ************************************************************************** */

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
void dbgOutputVal(unsigned int outVal) {  
    /*
    uint8_t maskVal_1 = outVal & 0b01111111;
    uint8_t portDMask = PORTD & 0b01111111;
    if (maskVal_1 != portDMask) {
        uint8_t MSB = PORTD & 0b10000000;
        MSB = MSB ^ 0b10000000;
        PORTD =  MSB | (uint8_t)outVal;
    } 
     */   
    //PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_D, PORTS_BIT_POS_7);  
    uint8_t maskD_1;
    uint8_t maskD_2;
    uint8_t outVal_1;
    maskD_1 = PORTD ^ 0b10000000;
    maskD_2 = maskD_1 & 0b10000000;
    outVal_1 = (uint8_t)outVal & 0b01111111;
    PORTD = maskD_2 | outVal_1 ;
}

/** 
  @Function
    void dbgUARTVal(unsigned char outVal) 
  @Summary
    This value will be written to the UART.
  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
void dbgUARTVal(const char *str) {
   
//   UARTSendString("The average is: ");
//   UARTSendString(str);
//   UARTSendString(" centimeters");
//   UARTSendString("\r\n");
}

/** 
  @Function
    dbgOutputLoc(unsigned int outVal)
  @Summary
    The value of outVal must be <= 127. This routine must verify this.
  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */
void dbgOutputLoc(unsigned int outVal) {
    PORTE = outVal ;
}

/** 
  @Function
    dbgStopCode(unsigned int outVal)
  @Summary
    This debug routine will stop everything when it called. It will also output an unique value if that happens
  @Remarks
    Refer to the example_file.h interface header for function usage details.
 */

void dbgStopCode(bool status, unsigned int loc ) {   
//    for(;;){
//      taskENTER_CRITICAL();            
//      PLIB_PORTS_PinDirectionOutputSet(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3); 
//      PLIB_PORTS_PinToggle(PORTS_ID_0, PORT_CHANNEL_A, PORTS_BIT_POS_3);
//      vTaskDelay(pdMS_TO_TICKS(100));
//      dbgOutputLoc(loc);
//      taskEXIT_CRITICAL();   
//    }    
}

void UARTSendString(const char* str) {
//    int k = 0;
//    while (k < strlen(str)) {
//        DRV_USART2_WriteByte(str[k]);
//        k++;
//    }
}


void dbgUARTVal2(char *outVal){
    SendUART_TRANSMIT_Message(outVal);
    SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
}
/* *****************************************************************************
 End of File
 */
