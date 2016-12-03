
// Author: Rodrigo

// Read string for Serial Communcation

void setup(){
  Serial.begin(9600);
}

void loop(){
  if(Serial.available()){
    String temp = Serial.readString();
    Serial.println(temp);
  }
  delay(100);
}
