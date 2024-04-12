#ifndef __SENSOR_H
#define __SENSOR_H

#include "stm32f4xx_hal.h"

#define DEV  6
#define HEAD 0xAA
#define TAIL 0xFF

// CMD List
#define START_M 0xC3
#define ACK_M   0x11

typedef enum {
    DAT_ERROR = 0,
    DAT_OK
} DataStatusType;

DataStatusType Rec_Ack(void);
DataStatusType Sensor_Rx(uint8_t *buf);
DataStatusType Sensor_TX_CMD(uint8_t cmd);

#endif