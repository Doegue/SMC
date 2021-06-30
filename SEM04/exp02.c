#pragma config FOSC = INTIO67
#pragma config PBADEN = OFF

#define _XTAL_FREQ 1000000

#include <xc.h>

void main(void) {
    TRISD &= 0b11111110;
    
    TRISB |= 0B00000001;    //Configurar o bit RB0 como entrada.
    INTCONbits.INT0IE = 1;  //Habilitar interrupção externa INT0.
    INTCONbits.INT0IF = 1;  //Limpar flag de interrupção INT0.
    INTCON2bits.INTEDG0 = 0;//Habilitar interrupção INT0 na borda de descida.
    RCONbits.IPEN = 0;      //Desligar todas as prioridades na interrupção.
    INTCONbits.GIE = 1;     //Hablitar interrupção geral.
    
    while(1){
        PORTD &= 0b11111110;
    }
    return;
}

void __interrupt() funcao(){
    if(INTCONbits.INT0E == 1){
        INTCONbits.INT0IF = 0;
        
        PORTD |= 0b00000001;
        __delay_ms(1000);
    }
}