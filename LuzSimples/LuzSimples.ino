
int pinLed = 12;

unsigned long tempoAnterior = 0;
unsigned long tempoMaximo = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(pinLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long tempoAtual =  millis();

  if(digitalRead(12)==LOW){
    digitalWrite(12, HIGH);
  }
  else{
    digitalWrite(12, LOW);
  }

  while(tempoAtual-tempoAnterior<tempoMaximo){
    tempoAtual = millis();
  }

  tempoAnterior = tempoAtual;

}
