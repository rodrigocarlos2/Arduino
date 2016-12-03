
// Author: Rodrigo

// Resistor: 100 ohms.

void setup(){
  pinMode(11, OUTPUT);
}

void loop(){
  if(digitalRead(11)){
    noTone(11);
  }
  else{
    tone(11, 1500);
  }
  delay(2000);
}
