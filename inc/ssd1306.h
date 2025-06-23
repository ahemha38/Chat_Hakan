#ifndef SSD1306_H
#define SSD1306_H

#include "stm32f4xx_hal.h"
#include <stdint.h>

typedef enum {
    Black = 0x00,
    White = 0x01
} SSD1306_COLOR;

void SSD1306_Init(I2C_HandleTypeDef *hi2c);
void SSD1306_Clear(void);
void SSD1306_UpdateScreen(void);
void SSD1306_DrawString(uint8_t x, uint8_t y, const char* str, const void* font, SSD1306_COLOR color);

#endif /* SSD1306_H */
