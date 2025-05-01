#ifndef SSD1306_H
#define SSD1306_H

#include "stm32f1xx_hal.h"
#include "fonts.h"

// SSD1306 OLED için I2C adresi
#define SSD1306_I2C_ADDR        0x3C

// Ekran boyutları
#define SSD1306_WIDTH           128
#define SSD1306_HEIGHT          64

// Temel OLED fonksiyonları
uint8_t ssd1306_Init(void);
void ssd1306_SetCursor(uint16_t x, uint16_t y);
void ssd1306_WriteString(const char* str, FontDef Font, uint16_t color);
void ssd1306_UpdateScreen(void);
void ssd1306_Fill(uint16_t color);

#endif /* SSD1306_H */
