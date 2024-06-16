/*
 * File:   newavr-main.c
 * Author: thato
 *
 * Created on 08 May 2023, 5:20 PM
 */
#include "lcd.h"

unsigned char cnt = 0;

void delay(void) {
    TCNT0 = 0x9D;   /*Load value for 0.1 sec delay*/
    TCCR0A = 0x00; /*Normal mode*/
    TCCR0B = 0x05;  /*1024 pre-scaler*/
    while((TIFR0 & 0x01) == 0); /*Wait for TOV0 flag*/
    TCCR0B = 0X00;  /*Stop the timer*/
    TIFR0 = 0x01;   /*Clear the TOV0 flag*/
    return;
}

void main(void) {
    DDRB |= (1 << PB0) | (1 << PB7);
    DDRB &= ~(1 << PB1);
    PORTB |= (1 << PB1);
    init();
    clear();
    write_string("Hello");
    _delay_ms(2000);
    clear();
    write_string("m:  s:  ms:  ");
    _delay_ms(1000);
    position(1, 3);
    write_string("00");
    _delay_ms(1000);
    position(1, 7);
    write_string("00");
    _delay_ms(1000);
    position(1, 12);
    write_string("00");
    _delay_ms(1000);
    while(1) {
        delay();
        cnt++;
        if (cnt >= 10) {
            PORTB ^= (1 << PB0);
            cnt = 0;
        }
        if ( (PINB & (1 << PB1)) == 0)
            PORTB ^= (1 << PB7);
    }
}

