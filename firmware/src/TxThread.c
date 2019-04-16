#include "TxThread.h"
#include <stdio.h>
#include <math.h>
#include "sensor_queue.h"
#include "debug.h"
#include "JSON.h"
void Tx_Tasks( void ) {
    BaseType_t check;
    static int MotorSequence, ArmSequence,PixelSequence,SensorSequence;
   
    while (1) {
        UNION_ message;
        check = ReceiveTransmit_Message(&message);
        
        dbgOutputLoc(0x38);
        if (check != pdTRUE) {
        }

        if (message.Mode == Motor) {
            cJSON * json = CreateJSON_Object();
            addNumberToJSON(json, "Sequence Number", MotorSequence);
            addStringToJSON(json, "Module name", "rover");
            if (message.operation == 0) {
                addStringToJSON(json, "Request type", "update");
            }
            else {
                addStringToJSON(json, "Request type", "getInfo");
            }
            
            if (message.Motor_Direction == 0) {
                addStringToJSON(json, "Direction", "Forward");
            }
            else if (message.Motor_Direction == 1) {
                addStringToJSON(json, "Direction", "Left");
            }
            else if (message.Motor_Direction == 2) {
                addStringToJSON(json, "Direction", "Right");
            }
            else  {
                addStringToJSON(json, "Direction", "Backward");
            }
            addNumberToJSON(json, "Left Rover Speed", message.Left_Motor_Speed);
            addNumberToJSON(json, "Right Rover Speed", message.Right_Motor_Speed);
            addNumberToJSON(json, "Left Rover Remaining Distance", message.Left_Motor_Distance);
            addNumberToJSON(json, "Right Rover Remaining Distance", message.Right_Motor_Distance);
            MotorSequence = MotorSequence + 1;
            sendRequest2(json);
        }
        else if (message.Mode == Arm) {
            cJSON * json = CreateJSON_Object();
            addNumberToJSON(json, "Sequence Number", ArmSequence);
            addStringToJSON(json, "Module name", "arm");
            if (message.operation == 0) {
                addStringToJSON(json, "Request type", "update");
            }
            else {
                addStringToJSON(json, "Request type", "getInfo");
            }
            if (message.arm_status == 0) {
                addStringToJSON(json, "Status", "Idle");
            }
            else {
                addStringToJSON(json, "Status", "Working");
            }
            addNumberToJSON(json, "Item Count", message.arm_item_count);
            ArmSequence = ArmSequence + 1;
            sendRequest2(json);
        }
        else if(message.Mode == Pixel) {
            cJSON * json = CreateJSON_Object();
            addNumberToJSON(json, "Sequence Number", PixelSequence);
            addStringToJSON(json, "Module name", "pixycam");
            if (message.operation == 0) {
                addStringToJSON(json, "Request type", "update");
            }
            else {
                addStringToJSON(json, "Request type", "getInfo");
            }
            if (message.Pixel_color == 1) {
                addStringToJSON(json, "Color", "Red");
            }
            else if(message.Pixel_color == 2) {
                addStringToJSON(json, "Color", "Green");
            }
            else if(message.Pixel_color == 3) {
                addStringToJSON(json, "Color", "Blue");
            }
            PixelSequence = PixelSequence + 1;
            sendRequest2(json);
        }
        else if (message.Mode == Sensor) {
            cJSON * json = CreateJSON_Object();
            addNumberToJSON(json, "Sequence Number", SensorSequence);
            addStringToJSON(json, "Module name", "distsensor");
            if (message.operation == 0) {
                addStringToJSON(json, "Request type", "update");
            }
            else {
                addStringToJSON(json, "Request type", "getInfo");
            }
            addNumberToJSON(json, "Distance to object", message.Sensor_distance);
            if (message.Find_result == 0) {
                addStringToJSON(json, "Find_result", "No object");
            }
            else if(message.Find_result == 1) {
                addStringToJSON(json, "Find_result", "Found an object");
            }
            
            SensorSequence = SensorSequence + 1;
            sendRequest2(json);
        }
    }
}
