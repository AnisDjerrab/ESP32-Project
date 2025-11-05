#include <Arduino.h>

#define YellowLed 4
#define RedLed 5
#define GreenLed 21


void setup() {
  pinMode(YellowLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);
}

void loop() {
  digitalWrite(YellowLed, HIGH);
  digitalWrite(RedLed, HIGH);
  digitalWrite(GreenLed, HIGH);
  sleep(100);
}
