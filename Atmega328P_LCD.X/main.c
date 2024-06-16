/* 
 * File:   main.c
 * Author: thato
 *
 * Created on 10 May 2023, 12:08 AM
 */
#include "lcd.h"

unsigned char cnt = 0;

void main(void) {
    init();
    clear();
    write_string("Hello Welcome");
    position(2, 0);
    write_string("Enter:");
    command(0x0D);
    _delay_ms(2000);
    
    while(1) {
        clear();
        cnt++;
        write_string("count : ");
        command(0xC0);
        write_char(cnt);
        _delay_ms(500);
    }
}

