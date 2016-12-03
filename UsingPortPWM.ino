

// Author: Rodrigo

int led = 11;
// It is a PWM Port

byte luminosidade;

void setup(){
  pinMode(led, OUTPUT);
  luminosidade = 0;
}

void loop(){
  
  if(luminosidade==255){
    luminosidade = 0;
  }
  else{
    if(255-luminosidade>25)
    	luminosidade+=25;
    else
      	luminosidade = 255;
  }
  
  analogWrite(led, luminosidade);
  
  delay(300);
  
}
