
// Author: Rodrigo Carlos
// E-mail: rodrigo19962010@live.com
// Tema: Refrigeração com gasto reduzido de energia

#include <JeeLib.h>
#include <avr/sleep.h>
#include <avr/power.h>
#include <dht.h>
#define dht_dpin A1 //Pino DATA do Sensor ligado na porta Analogica A1

dht DHT; //Inicializa o sensor

unsigned long temperaturaAtual;
unsigned long temperaturaDesejada;

int portaDoRefrigerador = 12;

ISR(WDT_vect){
  delay(1000);
}

void setup(){
  Serial.begin(9600);
  pinMode(portaDoRefrigerador, OUTPUT);
  temperaturaDesejada = 0;
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

  delay(100);

  Serial.print("Temperatura Desejada: ");
  Serial.println(temperaturaDesejada);

  delay(100);

  if(temperaturaAtual>temperaturaDesejada){
      
      // Ventilador forte
      Serial.println("Refrigerador ligado!");

      delay(100);
      
      temperaturaAtual = temperaturaAtual-2;
      digitalWrite(portaDoRefrigerador, HIGH);
    
  }
  else{

      Serial.println("Refrigerador desligado");

      delay(100);

      set_sleep_mode(SLEEP_MODE_PWR_SAVE);   /* EDIT: could also use SLEEP_MODE_PWR_DOWN for lowest power consumption. */
      
      sleep_enable();
      
      sleep_mode();

      sleep_disable();
      
      power_all_enable();
      
  }

}
