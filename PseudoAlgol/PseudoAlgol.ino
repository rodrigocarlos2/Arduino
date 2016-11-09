
// Author: Rodrigo Carlos
// E-mail: rodrigo19962010@live.com
// Pseudo-algoritmo 2016

int temperaturaAtual = 0;
int temperaturaDesejada = 0;

unsigned long tempoAnterior = 0;
unsigned long tempoMaximo = 1000;

void setup(){

  Serial.begin(9600);

  temperaturaAtual = 0;
  temperaturaDesejada = 0;

}

void loop(){

  unsigned long tempoAtual = millis();

  if(temperaturaAtual==0){
    Serial.println("Digite o valor da Temperatura atual: ");
  }

  while(temperaturaAtual==0){
  
    if(Serial.available()){
      temperaturaAtual = Serial.readString().toInt();
      
    }

  }

  if(temperaturaDesejada==0){
    Serial.println("Digite o valor da Temperatura desejada: ");
  }

  while(temperaturaDesejada==0){
    
      if(Serial.available()){
        temperaturaDesejada = Serial.readString().toInt();      
      }

  }

  Serial.print("Temperatura atual: ");
  Serial.println(temperaturaAtual);

  Serial.print("Temperatura desejada: ");
  Serial.println(temperaturaDesejada);

  if(temperaturaAtual>temperaturaDesejada){

    if(temperaturaAtual-temperaturaDesejada>10){
      // Ventilador forte
      Serial.println("Vento forte >>> ");
      temperaturaAtual = temperaturaAtual-2;
    }
    else{
        if(temperaturaAtual-temperaturaDesejada>5){
        // Ventilador médio
        Serial.println("Vento regular ZZZ ");
        temperaturaAtual = temperaturaAtual-2;
        }
        else{
          // Ventilador fraco
          Serial.println("Vento fraco ||| ");
          temperaturaAtual = temperaturaAtual-1;
        }
    }
    
  }
  else if(temperaturaAtual==temperaturaDesejada){
    randomSeed(analogRead(0));
    temperaturaAtual = temperaturaAtual+(random(3)-random(3));
  }
  else{
    Serial.println("Ventilador desligado temporariamente!");
    randomSeed(analogRead(0));
    temperaturaAtual = temperaturaAtual+(random(3)-random(3));
  }
  
  while(tempoAtual-tempoAnterior<tempoMaximo){
    tempoAtual = millis();
  }

  tempoAnterior = tempoAtual;

}
