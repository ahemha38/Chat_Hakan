#include "stm32f4xx_hal.h"
#include "bme280.h"
#include "ssd1306.h"
#include "fonts.h"
#include <stdio.h>

I2C_HandleTypeDef hi2c1;

static void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_I2C1_Init(void);

int main(void)
{
    HAL_Init();
    SystemClock_Config();
    MX_GPIO_Init();
    MX_I2C1_Init();

    BME280_Init(&hi2c1);
    SSD1306_Init(&hi2c1);

    char buffer[32];

    while (1)
    {
        float temp = BME280_ReadTemperature();
        float hum  = BME280_ReadHumidity();
        float pres = BME280_ReadPressure();

        SSD1306_Clear();
        snprintf(buffer, sizeof(buffer), "T: %.2f C", temp);
        SSD1306_DrawString(0, 0, buffer, &Font_7x10, White);
        snprintf(buffer, sizeof(buffer), "H: %.2f %%", hum);
        SSD1306_DrawString(0, 12, buffer, &Font_7x10, White);
        snprintf(buffer, sizeof(buffer), "P: %.2f hPa", pres);
        SSD1306_DrawString(0, 24, buffer, &Font_7x10, White);
        SSD1306_UpdateScreen();

        HAL_Delay(1000);
    }
}

/* System Clock, GPIO and I2C initialization functions below. */

static void SystemClock_Config(void)
{
    /* Configure clocks as needed */
}

static void MX_GPIO_Init(void)
{
    /* Configure GPIO pins as needed */
}

static void MX_I2C1_Init(void)
{
    hi2c1.Instance = I2C1;
    hi2c1.Init.ClockSpeed = 100000;
    hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
    hi2c1.Init.OwnAddress1 = 0;
    hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
    hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
    hi2c1.Init.OwnAddress2 = 0;
    hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
    hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
    HAL_I2C_Init(&hi2c1);
}
