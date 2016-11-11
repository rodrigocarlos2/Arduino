#include <JeeLib.h>

int pinLed = 13;

ISR(WDT_vect){
  Sleepy::watchdogEvent();
}

void setup() {
  // put your setup code here, to run once:

  pinMode(pinLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  digitalWrite(pinLed, HIGH);
  Sleepy::loseSomeTime(10000);
 //delay(10000);

  digitalWrite(pinLed, LOW);
  Sleepy::loseSomeTime(10000);
  //delay(10000);

}
