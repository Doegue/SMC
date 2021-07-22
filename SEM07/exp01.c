/*
 * File:   exp01.c
 * Author: esquadrao
 *
 * Created on 21 de Julho de 2021, 16:38
 */

#pragma config FOSC = INTIO67
#pragma config PBADEN = OFF

#define _XTAL_FREQ 1000000

#include <xc.h>

void __interrupt() interrupcao(){
     if (INTCONbits.INT0IF == 1) {
        __delay_ms(3000);
        PORTD &= 0b11111111;
        PORTD |= 0b00000001;
        __delay_ms(2000);
        
        for (int i = 0; i<5; i++){
            PORTD = 0b00000100;
            __delay_ms(250);
            PORTD = 0;
            __delay_ms(250);
        }
        __delay_ms(2000);
        
        for (int i = 0; i<5; i++){
            PORTD = 0b00001000;
            __delay_ms(250);
            PORTD = 0;
            __delay_ms(250);
        }
        for (int i = 0; i<5; i++){
            PORTD = 0b00010000;
            __delay_ms(250);
            PORTD = 0;
            __delay_ms(250);
        }
        for (int i = 0; i<5; i++){
            PORTD = 0b00100000;
            __delay_ms(250);
            PORTD = 0;
            __delay_ms(250);
        }
        for (int i = 0; i<5; i++){
            PORTD = 0b01000000;
            __delay_ms(250);
            PORTD = 0;
            __delay_ms(250);
        }
        for (int i = 0; i<5; i++){
            PORTD = 0b10000000;
            __delay_ms(250);
            PORTD = 0;
            __delay_ms(250);
        }
        INTCONbits.INT0IF = 0;
     }
}

void main(void) {
    TRISD &= 0b00000000; // Configura os pinos como saída digital
    PORTD &= 0b00000000; // Desliga os LEDs
    
    TRISB |= 0b00000001; 	 // Configurar o bit RB0 como entrada.
    INTCONbits.INT0IE = 1;   // Habilitar interrupção externa INT0
    INTCONbits.INT0IF = 0;   // Limpar flag da interrupção INT0
    INTCON2bits.INTEDG0 = 0; // Habilitar interrupção INT0 na borda de descida
    RCONbits.IPEN = 0;       // Desligar todas as prioridades na interrupção.
    INTCONbits.GIE = 1;      // Habilitar interrupção geral.
    
    TRISD = 0;
             
    return;
}