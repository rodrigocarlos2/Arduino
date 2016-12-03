
// Author: Rodrigo Carlos
// E-mail: rodrigo19962010@live.com

void setup(){

  Serial.begin(9600);

}

void loop(){

  byte var;
  // Variáveis do tipo byte variam entre 0 e 255.

  var = 0;

  while(var<10){
    if(var==7){
      continue;
    }
    Serial.println(var);
    delay(500);
  }

}
