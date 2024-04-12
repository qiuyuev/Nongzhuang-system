#include "sensor.h"
#include "usart.h"

/**
 * @brief 接收ACK
 *
 * @return DataStatusType 状态
 */
DataStatusType Rec_Ack(void)
{
    uint8_t temp = 0x00;
    HAL_UART_Receive(&huart3, &temp, 1, 100);
    if (temp == ACK_M)
        return DAT_OK;
    else
        return DAT_ERROR;
}

/**
 * @brief 接收传感器数据
 *
 * @param buf 接收数组指针
 * @return DataStatusType 状态
 */
DataStatusType Sensor_Rx(uint8_t *buf)
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

/**
 * @brief 发送命令
 *
 * @param cmd 发送给从机的命令
 * @return DataStatusType 状态
 */
DataStatusType Sensor_TX_CMD(uint8_t cmd)
{
    HAL_UART_Transmit(&huart3, &cmd, 1, 100);
    return DAT_OK;
}

/**
 * @brief 传感器相关任务
 *
 * @param buf 存储数据的数组指针
 * @return DataStatusType 状态
 */
DataStatusType Sensor_Task(uint8_t *buf)
{
    uint8_t repeat = 3;
resend:
    // 发送命令
    Sensor_TX_CMD(START_M);
    // 接收到响应
    if (Rec_Ack()) {
        // 接收数据
        if (Sensor_Rx(buf)) {
            return DAT_OK;
        } else {
            return DAT_ERROR;
        }

    } else if (repeat > 0) {
        repeat--;
        // 重发
        goto resend;
    }
    return DAT_ERROR;
}