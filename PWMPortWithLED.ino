
int led = 11;

byte luminosidade;

void setup(){
  Serial.begin(9600);
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
  
  Serial.print("Luminosidad: ");
  Serial.println(luminosidade);
  
  delay(800);
  
}
