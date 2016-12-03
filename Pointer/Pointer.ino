
// Author: Rodrigo Carlos

void add(int *n){
  *n=*n+1;
}

void setup(){
  Serial.begin(9600);
}

void loop(){
  
  int var = 0;
  
  point:
  
  Serial.println(var);
  
  if(var<10){
    add(&var);
    goto point;
    delay(400);
  }
  
}
