
// Author: Rodrigo

// Serial.setTimeout() is used to define the value of wait for a value in Serial.

void setup(){
  Serial.begin(9600);
  Serial.setTimeout(200);
  // Here - smaller, better.
}

void loop(){
  
  String number;
  int number_int=0;
  
  if(Serial.available()){
    number = Serial.readString();
  }
  
  number_int = number.toInt();
  
  if(number_int!=0)
  	Serial.println(number_int);
  
  delay(100);
}
