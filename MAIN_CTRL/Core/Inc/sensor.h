#ifndef __SENSOR_H
#define __SENSOR_H

#include "stm32f4xx_hal.h"

#define DEV  6
#define HEAD 0xAA
#define TAIL 0xFF

typedef enum {
    DAT_OK = 0,
    DAT_ERRROR
} DataStatusType;

DataStatusType Sensor_CMD_TX(uint8_t *cmd);
DataStatusType Sensor_Recevie(uint8_t *buf);

#endif