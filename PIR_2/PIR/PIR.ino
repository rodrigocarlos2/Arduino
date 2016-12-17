
int PIR=8;
// Port of PIR

void setup(){
  Serial.begin(9600);
  // Begin of the Serial Communication
  pinMode(PIR, INPUT);
}

void loop(){
  int action = digitalRead(PIR);
  // Entrance of PIR

  // Now, it is the action
  if(action==1){
    Serial.println("Movimento");
  }
  else{
    Serial.println("Parado");
  }

  delay(300);
}
