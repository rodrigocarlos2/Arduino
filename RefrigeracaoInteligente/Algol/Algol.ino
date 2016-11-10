
// Author: Rodrigo Carlos
// E-mail: rodrigo19962010@live.com
// Pseudo-algoritmo do Sistema de Refrigeração 2016

long temperaturaAtual = 0;
long temperaturaDesejada = 0;

unsigned long tempoAnterior = 0;
unsigned long tempoMaximo = 1000;

//int portaDaBateria = 12; Definição da porta da Bateria

void setup(){

  Serial.begin(9600);

  temperaturaAtual = 0;
  temperaturaDesejada = 0;

  // pinMode(portaDaBateria, OUTPUT);

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
        temperaturaAtual = temperaturaAtual-1.5;
        }
        else{
          // Ventilador fraco
          Serial.println("Vento fraco ||| ");
          temperaturaAtual = temperaturaAtual-0.5;
        }
    }
    
  }
  else if(temperaturaAtual==temperaturaDesejada){
    // Ventilador fraco
    randomSeed(analogRead(0));
    temperaturaAtual = temperaturaAtual+(random(3)-random(3));
  }
  else{
    // Aqui podemos economizar a energia elétrica
    // Ligar conexão com bateria
    Serial.println("Ventilador desligado temporariamente!");
    // digitalWrite(portaDaBateira, HIGH);
    randomSeed(analogRead(0));
    temperaturaAtual = temperaturaAtual+(random(3)-random(3));
  }
  
  while(tempoAtual-tempoAnterior<tempoMaximo){
    tempoAtual = millis();
  }

  tempoAnterior = tempoAtual;

  /*// Desligando a carga energética repassada já que no próximo laço a energia pode ser usada para mantimento do projeto
   * if(digitalRead(portaDaBateria)==HIGH){
   *  digitalWrite(portaDaBateria, LOW);
   * }
   */

}
