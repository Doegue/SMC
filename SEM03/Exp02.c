/*
 * File:   cod04.c
 * Author: Doegue N. da Silva
 *
 * Created on 23 de Junho de 2021, 21:45
 */
#define _XTAL_FREQ 1000000
#pragma config FOSC = INTIO67
#include <xc.h>

void main(void) {
    TRISD &= 0b11111100; // Configura os pinos RD0 e RD1 como saída digital.
    TRISB |= 0b00000001; // Configura o pino RB0 como saída digital.
    
    PORTD |= 0b00000010;
    
    while(1){
        if ((PORTB && 0b00000001) == 0){
            PORTD |= 0b00000001;
            PORTD &= 0b11111101;
        }    
    }
    return;
}
//Não Funcionou!