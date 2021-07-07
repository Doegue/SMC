//Sem05_exp01
int led1 = 12;
int led2 = 11;
int led3 = 10;
int led4 = 9;
int pinLDR = A0;
int valorSensor = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
 
}

void loop(){
  valorSensor = analogRead(pinLDR);
  Serial.println(valorSensor);

  if(valorSensor < 640){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  if(valorSensor >= 640 && valorSensor <= 768){
    digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
  }
  if(valorSensor >= 768 && valorSensor <= 896){
  	digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,LOW);
  }
  if(valorSensor > 896){
  	digitalWrite(led1,HIGH);
    digitalWrite(led2,HIGH);
    digitalWrite(led3,HIGH);
    digitalWrite(led4,HIGH);
  }
    
}