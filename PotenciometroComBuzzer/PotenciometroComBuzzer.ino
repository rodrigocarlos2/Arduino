
int pot = A2;
int buz = 8;

void setup(){
  Serial.begin(9600);
  pinMode(pot, INPUT);
  pinMode(buz, OUTPUT);
}

void loop(){
  int numPot = analogRead(pot);
  Serial.println(numPot);
  tone(buz, numPot, 10);
  delay(1);
}
