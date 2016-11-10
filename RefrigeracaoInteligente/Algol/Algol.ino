
// Author: Rodrigo Carlos
// E-mail: rodrigo19962010@live.com
// Pseudo-algoritmo do Sistema de Refrigeração 2016

#include <dht.h>
#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1

dht DHT; //Inicializa o sensor

unsigned long temperaturaAtual;
unsigned long temperaturaDesejada;

int portaDoRefrigerador = 12;

void setup(){

  Serial.begin(9600);
  pinMode(portaDoRefrigerador, OUTPUT);

}

void loop(){

  DHT.read11(dht_dpin); //Lê as informações do sensor

  temperaturaAtual = DHT.temperature;

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

    if(temperaturaAtual>=temperaturaDesejada){
      // Ventilador forte
      Serial.println("Vento forte >>> ");
      temperaturaAtual = temperaturaAtual-2;
      digitalWrite(portaDoRefrigerador, HIGH);
    }
    
  }
  else{
    // Aqui podemos economizar a energia elétrica
    // Ligar conexão com bateria
    Serial.println("Ventilador desligado temporariamente!");
    // digitalWrite(portaDaBateira, HIGH);
    digitalWrite(portaDoRefrigerador, LOW);
  }

  

}
