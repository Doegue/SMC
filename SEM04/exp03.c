#pragma config FOSC = INTIO67
#pragma config PBADEN = OFF

#define _XTAL_FREQ 1000000

#include <xc.h>

void main(void) {
    TRISD &= 0b00011000; //Configura os pinos RD0, RD1, RD2, RD5, RD6 e RD7, como saídas digitais.
    PORTD &= 0b11100111; //Desliga os Led's DS3 e DS4.
    TRISB |= 0B00000001;    //Configurar o bit RB0 como entrada.
    
    INTCONbits.INT0IE = 1;  //Habilitar interrupção externa INT0.
    INTCONbits.INT0IF = 1;  //Limpar flag de interrupção INT0.
    INTCON2bits.INTEDG0 = 0;//Habilitar interrupção INT0 na borda de descida.
    RCONbits.IPEN = 0;      //Desligar todas as prioridades na interrupção.
    INTCONbits.GIE = 1;     //Hablitar interrupção geral.
    
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

void __interrupt() funcao(){
    if(INTCONbits.INT0IE == 1){
        INTCONbits.INT0IF = 0;
        
        PORTD &= 0b00000000; //Desliga todos os led's.
        PORTD |= 0b10000100;
        __delay_ms(2000);
        PORTD &= 0b01111011;
            
    }
}