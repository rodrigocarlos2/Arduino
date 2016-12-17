
int PIR=8;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int action = digitalRead(PIR);

  if(action){
    Serial.println("Movimento");
  }
  else{
    Serial.println("Parado");
  }

  delay(300);
}
