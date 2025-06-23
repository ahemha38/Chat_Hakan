#ifndef FONTS_H
#define FONTS_H

#include <stdint.h>

typedef struct {
    uint8_t width;
    uint8_t height;
    const uint16_t *data;
} FontDef;

extern const FontDef Font_7x10;

#endif /* FONTS_H */
