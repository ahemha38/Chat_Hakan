#include "ssd1306.h"
#include <string.h>

static I2C_HandleTypeDef *oled_i2c;

#define SSD1306_ADDR 0x3C << 1

void SSD1306_Init(I2C_HandleTypeDef *hi2c)
{
    oled_i2c = hi2c;
    /* Initialization sequence for OLED */
}

void SSD1306_Clear(void)
{
    /* Clear display buffer */
}

void SSD1306_UpdateScreen(void)
{
    /* Send buffer to display */
}

void SSD1306_DrawString(uint8_t x, uint8_t y, const char* str, const void* font, SSD1306_COLOR color)
{
    /* Draw string on buffer - placeholder */
}
