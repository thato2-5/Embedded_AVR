/* 
 * File:   lcd.h
 * Author: thato
 *
 * Created on 09 May 2023, 11:48 PM
 */

#ifndef LCD_H
#define	LCD_H

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>

#define RS PB0
#define EN PB1
void command(unsigned char command);
void write_char(unsigned char data);
void write_string(const char *data);
void init(void);
void position(unsigned char row, unsigned char col);
void clear(void);

#endif	/* LCD_H */

