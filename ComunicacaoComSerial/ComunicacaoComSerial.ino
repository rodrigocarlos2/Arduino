
// Author: Rodrigo Carlos
// E-mail: rodrigo19962010@live.com

int temperaturaAtual;
int temperaturaDesejada;

unsigned long tempoAnterior = 0;
unsigned long tempoMaximo = 1000;

void setup() {

  Serial.begin(9600);

  temperaturaAtual = 0;
  temperaturaDesejada = 0;

}

void loop() {

  unsigned long tempoAtual = millis();

  Serial.println("Digite o valor da Temperatura atual: ");
  if(Serial.available()){
    temperaturaAtual = Serial.readString();
    Serial.print("Temperatura atual: ");
    Serial.println(temperaturaAtual);
  }

  Serial.println("Digite o valor da Temperatura desejada: ");
  if(Serial.available()){
    temperaturaAtual = Serial.readString();
    Serial.print("Temperatura desejada: ");
    Serial.println(temperaturaDesejada);
  }
  
  while(tempoAtual-tempoAnterior<tempoMaximo){
    tempoAtual = millis();
  }

  tempoAnterior = tempoAtual;

}
