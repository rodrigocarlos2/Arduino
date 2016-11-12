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

int portaDe5 = 10;

ISR(WDT_vect){
  Sleepy::watchdogEvent();
}

void setup(){
  Serial.begin(9600);
  pinMode(portaDoRefrigerador, OUTPUT);
  pinMode(portaDe5, OUTPUT);
  temperaturaDesejada = 0;
}

void loop(){

  digitalWrite(portaDe5, HIGH);
  
  if(temperaturaDesejada==0){
    Serial.println("Digite o valor da Temperatura desejada: ");
  }

  while(temperaturaDesejada==0){
    
      if(Serial.available()){
        temperaturaDesejada = Serial.readString().toInt();      
      }

  }

  DHT.read11(dht_dpin); //Lê as informações do sensor

  temperaturaAtual = DHT.temperature;

  Serial.print("Temperatura Atual: ");
  Serial.println(temperaturaAtual);

  delay(100);

  Serial.print("Temperatura Desejada: ");
  Serial.println(temperaturaDesejada);

  delay(100);

  if(temperaturaAtual>temperaturaDesejada){
      // Ventilador forte
      Serial.println("Refrigerador ligado!");
      temperaturaAtual = temperaturaAtual-2;
      digitalWrite(portaDoRefrigerador, HIGH);
    
  }
  else{
      Serial.println("Refrigerador desligado!");
      digitalWrite(portaDoRefrigerador, LOW);
  }

  digitalWrite(portaDe5, LOW);

  Sleepy::loseSomeTime(1000);

}
