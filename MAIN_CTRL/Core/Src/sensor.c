#include "sensor.h"
#include "usart.h"

/**
 * @brief 接收传感器数据
 *
 * @param cmd 发送给从机的命令地址
 * @return DataStatusType 状态
 */
DataStatusType Sensor_CMD_TX(uint8_t *cmd)
{
    HAL_UART_Transmit(&huart3, cmd, 1, 100);
    return DAT_OK;
}

/**
 * @brief 接收传感器数据
 *
 * @param buf 接收数组指针
 * @return DataStatusType 状态
 */
DataStatusType Sensor_Recevie(uint8_t *buf)
{
    uint8_t temp[DEV + 2] = {0x00};
    HAL_UART_Receive(&huart3, temp, DEV + 2, 100);
    if ((temp[0] == HEAD) && (temp[DEV + 1] == TAIL)) {
        for (uint8_t i = 1; i < DEV + 1; i++) {
            *buf = temp[i];
            buf++;
        }
        return DAT_OK;
    } else {
        return DAT_ERROR;
    }
}