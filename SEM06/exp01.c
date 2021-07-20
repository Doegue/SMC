#pragma config FOSC = INTIO67
#pragma config PBADEN = OFF
#define _XTAL_FREQ 1000000
#include <xc.h>

void __interrupt() interrupcao(){
     if (INTCONbits.INT0IF == 1) {
        __delay_ms(2000);
        if (PORTD == 24){
            for (int i = 0; i<10; i++){
                PORTD = 0b11111111;
                __delay_ms(250);
                PORTD = 0;
                __delay_ms(250);
            }
        }
        INTCONbits.INT0IF = 0;
     }
}

void main(void) {
    
    TRISB |= 0b00000001;    
    INTCONbits.INT0IE = 1;  //Habilitar interrupção externa INT0.
    INTCONbits.INT0IF = 0;  //Limpar flag de interrupção INT0.
    INTCON2bits.INTEDG0 = 0;//Habilitar interrupção INT0 na borda de descida.
    RCONbits.IPEN = 0;      //Desligar todas as prioridades na interrupção.
    INTCONbits.GIE = 1;     //Hablitar interrupção geral.
    TRISD = 0b00000000;
        
    while(1)
    {
        //PORTD &= 0b01111110; //Desliga os Led's DS0 e DS7.
        PORTD |= 0b00000011; //Liga DS0 e DS1
        __delay_ms(70);
        
        //PORTD &= 0b11111110; //Desliga o Led DS0
        PORTD = 0b00000110; //Liga DS1 e DS2
        __delay_ms(70);
        
        //PORTD &= 0b11111101; //Desliga o Led DS1
        PORTD = 0b00001100; //Liga DS2 e DS3
        __delay_ms(70);
        
        //PORTD &= 0b11111011; //Desliga os Led DS2
        PORTD = 0b00011000; //Liga DS3 e DS4
        __delay_ms(70);
        
        //PORTD &= 0b11110111; //Desliga os Led DS3
        PORTD = 0b00110000; //Liga DS4 e DS5
        __delay_ms(70);
        
        //PORTD &= 0b11101111; //Desliga os Led DS4
        PORTD = 0b01100000; //Liga DS5 e DS6
        __delay_ms(70);
        
        //PORTD &= 0b11011111; //Desliga os Led DS5
        PORTD = 0b11000000; //Liga DS6 e DS7
        __delay_ms(70);
        
        //PORTD &= 0b10111111; //Desliga os Led DS6
        PORTD = 0b10000001; //Liga DS0 e DS7
        __delay_ms(70);
    }
    return;
}