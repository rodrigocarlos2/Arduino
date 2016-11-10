
// Author: Rodrigo Carlos
// E-mail: rodrigo19962010@live.com
// Tema: Refrigeração com gasto reduzido de energia

#include <JeeLib.h>
#include <dht.h>
#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1

dht DHT; //Inicializa o sensor

unsigned long temperaturaAtual;
unsigned long temperaturaDesejada;

int portaDoRefrigerador = 12;

ISR(WDT_vect){
  Sleepy::watchdogEvent();
}

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

  Serial.print("Temperatura Atual: ");
  Serial.println(temperaturaAtual);

  Serial.print("Temperatura Desejada: ");
  Serial.println(temperaturaDesejada);

  if(temperaturaAtual>temperaturaDesejada){
      
      // Ventilador forte
      Serial.println("Refrigerador ligado!");
      temperaturaAtual = temperaturaAtual-2;
      digitalWrite(portaDoRefrigerador, HIGH);
    
  }
  else{
      // ventilador desligado
      Serial.println("Refrigerador desligado!");
      digitalWrite(portaDoRefrigerador, LOW);
  }

  Sleepy::loseSomeTime(2000);

}
