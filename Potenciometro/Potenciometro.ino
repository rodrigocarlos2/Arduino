
int pot = A2;

void setup(){
  Serial.begin(9600);
}

void loop(){
  int numPot = analogRead(pot);
  Serial.println(numPot);
  delay(100);
}
