# STM32 BME280 OLED Example

This repository contains a simple STM32F407G example project that reads
temperature, humidity and pressure from a BME280 sensor and displays
the results on an SSD1306 OLED screen using the HAL library.

The code is split into small source files under `src/` and headers under
`inc/`. You can integrate these files into a project generated with
STM32CubeMX or your preferred build system. Hardware initialization
functions are simplified and should be adjusted for your board layout.
