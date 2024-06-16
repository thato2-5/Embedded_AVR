/* 
 * File:   lcd.c
 * Author: thato
 *
 * Created on 09 May 2023, 8:42 AM
 */

#include "lcd.h"

void command(unsigned char command) {
    PORTD = (PORTD & 0x0F) | (command & 0xF0);
    PORTD &= ~(1 << RS);
    PORTD |= (1 << EN);
    _delay_us(2);
    PORTD &= ~(1 << EN);
    _delay_us(200);
    
    PORTD = (PORTD & 0x0F) | (command << 4);
    PORTD &= ~(1 << RS);
    PORTD |= (1 << EN);
    _delay_us(2);
    PORTD &= ~(1 << EN);
    _delay_us(200);
    return;
}
void write_char(unsigned char data) {
    PORTD = (PORTD & 0x0F) | (data & 0xF0);
    PORTD |= (1 << RS);
    PORTD |= (1 << EN);
    _delay_us(2);
    PORTD &= ~(1 << EN);
    _delay_us(200);
    
    PORTD = (PORTD & 0x0F) | (data << 4);
    PORTD |= (1 << RS);
    PORTD |= (1 << EN);
    _delay_us(2);
    PORTD &= ~(1 << EN);
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
    DDRD = 0xFF;
    _delay_ms(20);
    command(0x33);
    command(0x32);
    command(0x28);
    command(0x0C);
    command(0x06);
    command(0x01);
    _delay_ms(5);
    return;
}
void clear(void) {
    command(0x01);
    _delay_ms(2);
    command(0x80);
    return;
}
void position(unsigned char row, unsigned char col) {
    if (row == 1 && col < 16)
        command((row & 0x0F) | 0x80);
    else if (row == 2 && col < 16)
        command((row & 0x0F) | 0xC0);
    return;
}
