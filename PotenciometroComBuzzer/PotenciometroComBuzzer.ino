
int pot = A2;

void setup(){
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(8, OUTPUT);
}

void loop(){
  int numPot = analogRead(pot);
  Serial.println(numPot);
  tone(8, numPot);
  delay(100);
}
