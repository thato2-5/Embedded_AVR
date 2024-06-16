#include "lcd.h"

void command(unsigned char command) {
    PORTB = (PORTB & 0x0F) | (command & 0xF0);
    PORTB &= ~(1 << RS);
    PORTB |= (1 << EN);
    _delay_us(2);
    PORTB &= ~(1 << EN);
    _delay_us(200);
    
    PORTB = (PORTB & 0x0F) | (command << 4);
    PORTB &= ~(1 << RS);
    PORTB |= (1 << EN);
    _delay_us(2);
    PORTB &= ~(1 << EN);
    _delay_us(200);
    
    return;
}
void write_char(unsigned char data) {
    PORTB = (PORTB & 0x0F) | (data & 0xF0);
    PORTB |= (1 << RS);
    PORTB |= (1 << EN);
    _delay_us(2);
    PORTB &= ~(1 << EN);
    _delay_us(200);
    
    PORTB = (PORTB & 0x0F) | (data << 4);
    PORTB |= (1 << RS);
    PORTB |= (1 << EN);
    _delay_us(2);
    PORTB &= ~(1 << EN);
    _delay_us(200);
    
    return;
}
void write_string(const char *data) {
    uint8_t i;
    for (i = 0; data[i] != 0; i++)
        write_char(data[i]);
    
    return;
}
void init(void) {
    DDRB = 0xFF;
    _delay_ms(20);
    command(0x33);
    command(0x32);
    command(0x28);
    command(0x0C);
    command(0x06);
    command(0x01);
    
    return;
}
void position(unsigned char row, unsigned char col) {
    if (row == 1 && col < 16)
        command((row & 0x0F) | 0x80);
    else if (row == 2 && col < 16)
        command((row & 0x0F) | 0xC0);
    
    return;
}
void clear(void) {
    command(0x01);
    _delay_ms(5);
    command(0x80);
    
    return;
}
