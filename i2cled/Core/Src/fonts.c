#include "fonts.h"

// 7x10 boyutunda font tanımı
const uint8_t Font_7x10_Table[] = {
    // Bu array, 7x10 fontunun karakter tablosunu içerir
    // Karakter 'A' için örnek veri:
    0x7E, 0x09, 0x09, 0x09, 0x7E, // 'A' karakteri
    0x7F, 0x49, 0x49, 0x49, 0x36, // 'B' karakteri
    // Diğer karakterler burada devam eder...
};

FontDef Font_7x10 = {Font_7x10_Table, 7, 10};  // 7x10 fontunun boyutları ve karakter tablosu

// 11x18 boyutunda font tanımı
const uint8_t Font_11x18_Table[] = {
    // 11x18 boyutunda font karakter tablosu
    // Karakter 'A' için örnek veri:
    0x0F, 0x14, 0x14, 0x14, 0x0F, 0x14, 0x14, 0x14, 0x0F, // 'A' karakteri
    0x1F, 0x15, 0x15, 0x15, 0x0A, 0x15, 0x15, 0x15, 0x1F, // 'B' karakteri
    // Diğer karakterler burada devam eder...
};

FontDef Font_11x18 = {Font_11x18_Table, 11, 18};  // 11x18 fontunun boyutları ve karakter tablosu
