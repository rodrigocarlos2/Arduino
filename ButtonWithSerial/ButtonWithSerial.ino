
// Author: Rodrigo

button = 12;

void setup(){
  Serial.begin(9600);
  pinMode(button, INPUT);
}

void loop(){

  byte result = digitalRead(button);

  if(result==HIGH){
    Serial.println("H");
  }
  else{
    Serial.println("L");
  }

}
