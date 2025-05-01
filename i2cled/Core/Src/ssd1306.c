#include "ssd1306.h"

// SSD1306 ekran buffer
uint8_t SSD1306_Buffer[SSD1306_WIDTH * SSD1306_HEIGHT / 8];

// I2C iletişim fonksiyonu
static void ssd1306_WriteCommand(uint8_t command) {
    HAL_I2C_Mem_Write(&hi2c1, SSD1306_I2C_ADDR << 1, 0x00, 1, &command, 1, HAL_MAX_DELAY);
}

// Ekranı başlat
uint8_t ssd1306_Init(void) {
    HAL_Delay(100); // OLED başlatma gecikmesi

    // OLED ekranı başlatmak için komutlar
    ssd1306_WriteCommand(0xAE); // Display off
    ssd1306_WriteCommand(0x20); // Memory addressing mode
    ssd1306_WriteCommand(0x10); // Page addressing mode
    ssd1306_WriteCommand(0xB0); // Page start address
    ssd1306_WriteCommand(0xC8); // COM output scan direction
    ssd1306_WriteCommand(0x00); // Lower column start address
    ssd1306_WriteCommand(0x10); // Higher column start address
    ssd1306_WriteCommand(0x40); // Display start line
    ssd1306_WriteCommand(0x81); // Set contrast control
    ssd1306_WriteCommand(0xFF); // Max contrast
    ssd1306_WriteCommand(0xA1); // Segment re-map
    ssd1306_WriteCommand(0xA6); // Normal display
    ssd1306_WriteCommand(0xA8); // Multiplex ratio
    ssd1306_WriteCommand(0x3F);
    ssd1306_WriteCommand(0xD3); // Display offset
    ssd1306_WriteCommand(0x00);
    ssd1306_WriteCommand(0xD5); // Display clock divide ratio
    ssd1306_WriteCommand(0xF0);
    ssd1306_WriteCommand(0xD9); // Pre-charge period
    ssd1306_WriteCommand(0x22);
    ssd1306_WriteCommand(0xDA); // COM pins hardware configuration
    ssd1306_WriteCommand(0x12);
    ssd1306_WriteCommand(0xDB); // VCOMH deselect level
    ssd1306_WriteCommand(0x20);
    ssd1306_WriteCommand(0x8D); // Enable charge pump regulator
    ssd1306_WriteCommand(0x14);
    ssd1306_WriteCommand(0xAF); // Display on

    return 1; // Başarılı
}

// Ekran bufferını güncelle
void ssd1306_UpdateScreen(void) {
    for (uint8_t i = 0; i < 8; i++) {
        ssd1306_WriteCommand(0xB0 + i);
        ssd1306_WriteCommand(0x00);
        ssd1306_WriteCommand(0x10);

        HAL_I2C_Mem_Write(&hi2c1, SSD1306_I2C_ADDR << 1, 0x40, 1, &SSD1306_Buffer[SSD1306_WIDTH * i], SSD1306_WIDTH, HAL_MAX_DELAY);
    }
}

// Ekranı doldur
void ssd1306_Fill(uint8_t color) {
    for (uint16_t i = 0; i < sizeof(SSD1306_Buffer); i++) {
        SSD1306_Buffer[i] = (color == SSD1306_COLOR_WHITE) ? 0xFF : 0x00;
    }
}

// İmleci ayarla
void ssd1306_SetCursor(uint8_t x, uint8_t y) {
    // İmleç pozisyonunu ayarla
}

// Yazı yaz
void ssd1306_WriteString(const char* str, FontDef Font, uint8_t color) {
    // Yazı fonksiyonunu yaz
}
