#ifndef STM32F4XX_HAL_H
#define STM32F4XX_HAL_H

#include <stdint.h>

typedef struct {
    void* Instance;
    struct {
        uint32_t ClockSpeed;
        uint32_t DutyCycle;
        uint32_t OwnAddress1;
        uint32_t AddressingMode;
        uint32_t DualAddressMode;
        uint32_t OwnAddress2;
        uint32_t GeneralCallMode;
        uint32_t NoStretchMode;
    } Init;
} I2C_HandleTypeDef;

#define I2C_DUTYCYCLE_2 0
#define I2C_ADDRESSINGMODE_7BIT 0
#define I2C_DUALADDRESS_DISABLE 0
#define I2C_GENERALCALL_DISABLE 0
#define I2C_NOSTRETCH_DISABLE 0
#define I2C1 ((void*)0)

#define HAL_MAX_DELAY 0xFFFFFFFFU

static inline void HAL_I2C_Init(I2C_HandleTypeDef *hi2c) {(void)hi2c;}
static inline void HAL_I2C_Mem_Read(I2C_HandleTypeDef *hi2c, uint16_t devAddr, uint16_t memAddr, uint16_t memAddSize, uint8_t *pData, uint16_t size, uint32_t timeout) {
    (void)hi2c; (void)devAddr; (void)memAddr; (void)memAddSize; (void)pData; (void)size; (void)timeout;
}
static inline void HAL_Delay(uint32_t ms) {(void)ms;}
static inline void HAL_Init(void) {}

#endif /* STM32F4XX_HAL_H */
