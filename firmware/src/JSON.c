#include "JSON.h"
#include "system_config.h"
#include "system_definitions.h"
CJSON_PUBLIC(cJSON *) CreateJSON_Object() {
    cJSON *temp = cJSON_CreateObject();
    return temp;
}

void addStringToJSON(cJSON * const object, const char * const name, const char * const string) {
    cJSON_AddStringToObject(object, name, string);
}

void addNumberToJSON(cJSON * const object, const char * const name, const double number) {
    cJSON_AddNumberToObject(object, name, number);
}

CJSON_PUBLIC(char *) JSONtoString(const cJSON *item) {
    return cJSON_PrintUnformatted(item);
}

void MD5(const char *data, unsigned char *result) {
    MD5_CTX a;
    MD5_Init(&a);
    MD5_Update(&a, data,strlen(data));
    MD5_Final(result, &a);
}


CJSON_PUBLIC(cJSON *) parsing(const char *value){
    return cJSON_ParseWithOpts(value, 0, 0);
}

CJSON_PUBLIC(char *) getStringTypeObject(cJSON * const object, const char *name) {
    cJSON *data = cJSON_GetObjectItem(object, name);
    if (!data) {
        return NULL;  
    }
    return data->valuestring;
}

double getDoubleTypeObject(cJSON * const object, const char *name) {
    cJSON *data = cJSON_GetObjectItem(object, name);
    if (!data) {
        return 0;  
    }
    return data->valuedouble;
}

void deleteJSON(cJSON *item) {
    cJSON_Delete(item);
}
void sendRequest(cJSON *item, cJSON *json2) {
    char *json_data = JSONtoString(item);
    unsigned char result[16];
    MD5(json_data, result);
    char converted[33];
    int k =0;
    for (k=0;k<16;k<k++){
        sprintf(&converted[k*2], "%02x", result[k]);
    }
    addStringToJSON(json2, "HASH", converted);
    cJSON_AddItemToObject(json2, "JSON PAYLOAD", item);
     char *json_data2 = JSONtoString(json2);
     char* start_byte = "[";
     char* end_byte = "]";
     
     char* name_with_extension;
     name_with_extension = pvPortMalloc(strlen(json_data2)+1+2); /* make space for the new string (should check the return value ...) */
     strcpy(name_with_extension, start_byte); /* copy name into the new var */
     strcat(name_with_extension, json_data2); /* add the extension */
     strcat(name_with_extension, end_byte); /* add the extension */
     //dbgUARTVal2(name_with_extension);
     SendUART_TRANSMIT_Message(name_with_extension);
     SYS_INT_SourceEnable(INT_SOURCE_USART_1_TRANSMIT);
     vPortFree(json_data);
     vPortFree(json_data2);
     vPortFree(start_byte);
     vPortFree(end_byte);
     vPortFree(name_with_extension);
    
     deleteJSON(item);
     deleteJSON(json2);
}
unsigned int_to_int(unsigned k) {
    if (k == 0) return 0;
    if (k == 1) return 1;                       /* optional */
    return (k % 2) + 10 * int_to_int(k / 2);
}
void sendRequest2(cJSON *item) {
    char *json_data = JSONtoString(item);
    unsigned char result[16];
    MD5(json_data, result);
    char converted[33];
    int k =0;
    for (k=0;k<16;k<k++){
        sprintf(&converted[k*2], "%02x", result[k]);
    }
     int len = int_to_int(strlen(json_data)+ 32);
     char *len_ = pvPortMalloc(10);
     sprintf(len_, "%0d", len);
     char* name_with_extension;
     name_with_extension = pvPortMalloc(strlen(json_data)+1+2 + 10 + 33); /* make space for the new string (should check the return value ...) */
     strcpy(name_with_extension, "["); /* copy name into the new var */
     int i = 0;
     for (i = 0; i<10-strlen(len_);i++){
         strcat(name_with_extension, "0"); /* add the extension */
     }
     strcat(name_with_extension, len_); /* add the extension */
     strcat(name_with_extension, converted); /* add the extension */
     strcat(name_with_extension, json_data); /* add the extension */
     strcat(name_with_extension, "]"); /* add the extension */
//     int j  = 0;
//     for(j = 0; j< strlen(name_with_extension);j++){
//         while (PLIB_USART_TransmitterBufferIsFull(USART_ID_1)){}
//         PLIB_USART_TransmitterByteSend(USART_ID_1, name_with_extension[j]);
//     }
     dbgUARTVal2(name_with_extension);
     
     vPortFree(json_data);
     vPortFree(len_);
     vPortFree(name_with_extension);
    
     deleteJSON(item);
}
void sendRequest3(mode_ Mode,uint8_t operation, uint8_t val1, uint8_t val2, uint8_t val3, int val4, int val5,int val6) {
    UNION_ Union;
    Union.Mode = Mode;
    Union.operation = operation;
    if (Mode == Motor) {
        Union.Motor_Direction = val1;
        Union.Left_Motor_Speed = val2;
        Union.Right_Motor_Speed = val3;
        Union.Left_Motor_Distance = val4;
        Union.Right_Motor_Distance = val5;
        Union.arm_status = 0;
        Union.arm_item_count = 0;
        Union.Pixel_color = 0;
        Union.Sensor_distance = 0;
    }
    else if (Mode == Arm) {
        Union.Motor_Direction = 0;
        Union.Left_Motor_Speed = 0;
        Union.Right_Motor_Speed = 0;
        Union.Left_Motor_Distance = 0;
        Union.Right_Motor_Distance = 0;
        Union.arm_status = val1;
        Union.arm_item_count = val2;
        Union.Pixel_color = 0;
        Union.Sensor_distance = 0;
    }
    else if (Mode == Pixel) {
        Union.Motor_Direction = 0;
        Union.Left_Motor_Speed = 0;
        Union.Right_Motor_Speed = 0;
        Union.Left_Motor_Distance = 0;
        Union.Right_Motor_Distance = 0;
        Union.arm_status = 0;
        Union.arm_item_count = 0;
        Union.Pixel_color = val1;
        Union.Sensor_distance = 0;
    }
    else if (Mode == Sensor) {
        Union.Motor_Direction = 0;
        Union.Left_Motor_Speed = 0;
        Union.Right_Motor_Speed = 0;
        Union.Left_Motor_Distance = 0;
        Union.Right_Motor_Distance = 0;
        Union.arm_status = 0;
        Union.arm_item_count = 0;
        Union.Pixel_color = 0;
        Union.Sensor_distance = val4;
        Union.Find_result = val6;
    }
    else {
        return;
    }
    BaseType_t success = SendTransmit_Message(&Union);
    if (success == pdFALSE) {
    }
}


