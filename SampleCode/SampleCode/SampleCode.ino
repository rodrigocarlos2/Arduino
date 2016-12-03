
#include <dht.h>
// Bibliotecas

void setup(){
  Serial.begin(9600);
}

void loop(){

  char message;

  if(Serial.available()>0){

      while(Serial.available()>0){
        message = Serial.read();
        Serial.print(message);
      }
      Serial.println(" ");

  }

  delay(300);
  
}

