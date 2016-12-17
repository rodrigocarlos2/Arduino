
void setup(){
  pinMode(A0, OUTPUT);
}

void loop(){
  analogWrite(A0, 100);
  delay(2000);
  analogWrite(A0, 700);
  delay(2000);
  analogWrite(A0, 1200);
  delay(2000);
}
