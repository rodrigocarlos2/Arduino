
// Program for action a LED with a BUTTON

int button = 12;
int led = 10;

void setup(){

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
  
  digitalWrite(button, 1);
  // On Internal Resistance
}

void loop(){

  byte onOrOff = digitalRead(button);
  
  if(OnOff==0){
    byte state = digitalRead(led);
    
    if(state==1){
      digitalWrite(led, 0);
    }
    else{
      digitalWrite(led, 1);
    }
    
  }
  
}
