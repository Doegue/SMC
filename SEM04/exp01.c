#pragma config FOSC = INTIO67
#pragma config PBADEN = OFF

#define _XTAL_FREQ 1000000


#include <xc.h>

void main(void) {
    TRISD &= 0b00011000; //Configura os pinos RD0, RD1, RD2, RD5, RD6 e RD7, como saídas digitais.
    PORTD &= 0b11100111; //Desliga os Led's DS3 e DS4.
    
    while(1)
    {
        PORTD &= 0b10111011; //Desliga os Led's DS2 e DS6.
        PORTD |= 0b10000001; //Liga DS0 e DS7
        __delay_ms(3000);
        
        PORTD &= 0b01111110; //Desliga os Led's DS0 e DS7.
        PORTD |= 0b10000010; //Liga DS1 e DS7
        __delay_ms(1000);
        
        PORTD &= 0b01111101; //Desliga os Led's DS1 e DS7.
        PORTD |= 0b00100100; //Liga DS2 e DS5
        __delay_ms(3000);
        
        PORTD &= 0b11011011; //Desliga os Led's DS2 e DS5.
        PORTD |= 0b01000100; //Liga DS2 e DS6
        __delay_ms(1000);
    }
    return;
}