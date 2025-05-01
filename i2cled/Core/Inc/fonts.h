#ifndef FONTS_H
#define FONTS_H

#include <stdint.h>
#include <stddef.h>

typedef struct {
    const uint8_t* data;
    uint8_t width;
    uint8_t height;
} FontDef;

// Yazı tipleri
extern FontDef Font_7x10;
extern FontDef Font_11x18;

#endif /* FONTS_H */
