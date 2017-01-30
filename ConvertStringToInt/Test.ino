
//Author: Rodrigo Carlos
//Problem: Convert String to Integer in Arduino Language

void setup(){
  Serial.begin(9600);
}

void loop(){
  String tal = "123";
  int i = tal.toInt();
  Serial.println(i);
}
