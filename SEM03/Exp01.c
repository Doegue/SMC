/*
 * File:   cod3.c
 * Author: Doegue N. da Silva
 *
 * Created on 23 de Junho de 2021, 21:08
 */

#pragma config FOSC = INTIO67
#include <xc.h>

void main(void) {
    TRISD &= 0b11101010;
    
    while(1)
    {
        PORTD |= 0b00010101; // Escreve nível lógico alto ('1') no pino RD0, RD2, RD4
    }
        
    return;
}
