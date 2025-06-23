#ifndef BME280_H
#define BME280_H

#include "stm32f4xx_hal.h"

void BME280_Init(I2C_HandleTypeDef *hi2c);
float BME280_ReadTemperature(void);
float BME280_ReadHumidity(void);
float BME280_ReadPressure(void);

#endif /* BME280_H */
