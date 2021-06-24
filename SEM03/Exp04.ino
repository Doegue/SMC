void setup() {
  DDRB = DDRB | B00110000; //Configura as portas 4(pin10 PWM) e 5(pin11) PWM) como sáida digital.

}

void loop() {
  PORTB = PORTB | B00110000; //Registra valor HIGH na porta digital 4 e 5/Pino digital 10 e 11(PWM).

}