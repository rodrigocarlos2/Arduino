
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
  // Cão de guarda
}
// Extremamente necessário para parar o LoseSomeTime.

void setup(){
  Serial.begin(9600);
  pinMode(portaDoRefrigerador, OUTPUT);
  temperaturaDesejada = 0;
}

void loop(){

  temperaturaAtual = 0;

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

  delay(100);

  Serial.print("Temperatura Desejada: ");
  Serial.println(temperaturaDesejada);

  delay(100);

  if(temperaturaAtual>temperaturaDesejada){
      
      // Ventilador forte
      Serial.println("Refrigerador forte!");
      delay(100);
      digitalWrite(portaDoRefrigerador, HIGH);
    
  }
  else{

      // Ventilador desligado
      Serial.println("Refrigerador desligado!");
      delay(100);
      digitalWrite(portaDoRefrigerador, LOW);
      
  }

  Sleepy::loseSomeTime(2000);
  //delay(1000); Opção alternativa

}
