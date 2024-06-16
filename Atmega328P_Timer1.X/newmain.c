/*
 * File:   newmain.c
 * Author: thato
 *
 * Created on 10 May 2023, 1:31 AM
 */
#include <avr/io.h>

uint8_t cnt = 0;

void delay(void) {
    TCNT1 = 0xFC2E;
    TCCR1A = 0x00;
    TCCR1B = 0x05;
    while((TIFR1 & 0x01) == 0);
    TCCR1B = 0x00;
    TIFR1 = 0x01;
    return;
}

void main(void) {
    DDRD |= (1 << PD0);
    while(1) {
        delay();
        cnt++;
        if (cnt >= 5) {
            PORTD ^= (1 << PD0);
            cnt = 0;
        }
    }
}
