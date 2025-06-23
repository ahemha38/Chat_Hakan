#include "bme280.h"

static I2C_HandleTypeDef *bme_i2c;

#define BME280_ADDR 0x76 << 1

void BME280_Init(I2C_HandleTypeDef *hi2c)
{
    bme_i2c = hi2c;
    /* Initialization sequence for BME280 */
}

float BME280_ReadTemperature(void)
{
    uint8_t data[3] = {0};
    /* Read temperature registers */
    HAL_I2C_Mem_Read(bme_i2c, BME280_ADDR, 0xFA, 1, data, 3, HAL_MAX_DELAY);
    int32_t adc_T = (data[0] << 12) | (data[1] << 4) | (data[2] >> 4);
    /* Convert to degrees Celsius using compensation formula (simplified) */
    return adc_T / 100.0f;
}

float BME280_ReadHumidity(void)
{
    uint8_t data[2] = {0};
    HAL_I2C_Mem_Read(bme_i2c, BME280_ADDR, 0xFD, 1, data, 2, HAL_MAX_DELAY);
    int32_t adc_H = (data[0] << 8) | data[1];
    return adc_H / 1024.0f;
}

float BME280_ReadPressure(void)
{
    uint8_t data[3] = {0};
    HAL_I2C_Mem_Read(bme_i2c, BME280_ADDR, 0xF7, 1, data, 3, HAL_MAX_DELAY);
    int32_t adc_P = (data[0] << 12) | (data[1] << 4) | (data[2] >> 4);
    return adc_P / 256.0f;
}
