#include "fonts.h"

/* Simple placeholder font data: 95 characters, 10 lines each */
static const uint16_t Font7x10_Table[95 * 10] = {0};

const FontDef Font_7x10 = {
    .width = 7,
    .height = 10,
    .data = Font7x10_Table
};
