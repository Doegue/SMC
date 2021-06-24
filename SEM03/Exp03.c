/*
 * File:   cod05.c
 * Author: Doegue N. da Silva
 *
 * Created on 23 de Junho de 2021, 22:59
 */

#define _XTAL_FREQ 1000000
#pragma config FOSC = INTIO67
#include <xc.h>

void main(void) {
    TRISD &= 0b11000111;
    
    while(1)
    {
        PORTD |= 0b00001000;
        __delay_ms(3000);
        PORTD &= 0b11110111;
        PORTD |= 0b00010000;
        __delay_ms(1000);
        PORTD &= 0b11101111;
        PORTD |= 0b00100000;
        __delay_ms(2000);
        PORTD &= 0b11011111;
        __delay_ms(2000);
    }
    
    return;
}
