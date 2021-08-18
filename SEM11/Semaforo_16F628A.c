#include <16f628a.h>  // Inclui o cabeçalho especifico do pic a ser usado

#FUSES NOWDT          //No Watch Dog Timer
#FUSES HS            //High speed Osc (> 4mhz)
#FUSES NOPUT         //No Power Up Timer
#FUSES NOPROTECT          //Code not protected from reading
#FUSES BROWNOUT      //Reset when brownout detected
#FUSES MCLR          //Master Clear pin enabled
#FUSES NOCPD         //No EE protection
#use delay(clock=20M)     // Seta o clock interno para 20Mhz

#define L_VERMELHO1  PIN_B4
#define L_VERMELHO2  PIN_B2
#define L_VERDE1     PIN_B1
#define L_VERDE2     PIN_B5
#define L_AMARELO1   PIN_B3
#define L_AMARELO2   PIN_B0


void main(void) // função principal

{
	 do {
		  /*

		  S1 S2
		  O  X
		  O  O
		  X  O

		  */

		  output_high(L_VERMELHO2);
		  output_high(L_VERDE1);
		  output_low(L_AMARELO2);
		  output_low(L_VERMELHO1);
		  delay_ms(3000);

		  /*

		  S1 S2
		  O  X
		  X  O
		  O  O

		  */

		  output_low(L_VERDE1);
		  output_high(L_AMARELO1);
		  delay_ms(1000);

		  /*

		  S1 S2
		  X  O
		  O  O
		  O  X

		  */

		  output_low(L_VERMELHO2);
		  output_high(L_VERDE2);
		  output_low(L_AMARELO1);
		  output_high(L_VERMELHO1);
		  delay_ms(3000);

		  /*

		  S1 S2
		  X  O
		  O  X
		  O  O
		  */

		  output_low(L_VERDE2);
		  output_high(L_AMARELO2);
		  delay_ms(1000);

	 } while (TRUE); // mantem o laço de repetição rodando em loop infinito
}

// FIM DO CÓDIGO