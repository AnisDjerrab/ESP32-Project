#include <Arduino.h>

#define YellowLed 4
#define RedLed 5
#define GreenLed 21
#define RGB_R 19
#define RGB_G 22
#define RGB_B 23

bool RGBCoolEffects = true;
bool Increment = true; // increment or decrement the RGB light value.
int value[3] = {0, 0, 0}; // R, G and B values.

void setup() {
  pinMode(YellowLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(GreenLed, OUTPUT);

  ledcSetup(0, 5000, 8); // number (0), frequency (5Khz), and amount of possibilities (max number of bits -> 8 = 255).
  ledcSetup(1, 5000, 8);
  ledcSetup(2, 5000, 8);
  ledcAttachPin(RGB_R, 0);
  ledcAttachPin(RGB_G, 1);
  ledcAttachPin(RGB_B, 2);

  digitalWrite(YellowLed, HIGH);
  digitalWrite(RedLed, HIGH);
  digitalWrite(GreenLed, HIGH);
}

void loop() {
  // Dynamic Lightning of the RGB
  if (Increment) {
    if (value[0] < 255) {
      value[0]++;
    } else if (value[1] < 255) {
      value[1]++;
    } else if (value[2] < 255) {
      value[2]++;
    } else {
      value[0]--;
      Increment = false;
    }
  } else {
    if (value[0] > 0) {
      value[0]--;
    } else if (value[1] > 0) {
      value[1]--;
    } else if (value[2] > 0) {
      value[2]--;
    } else {
      value[0]++;
      Increment = true;
    }
  }
  // Apply the Dynamic value to the RGB light.
  ledcWrite(0, value[0]);
  ledcWrite(1, value[1]);
  ledcWrite(2, value[2]); 
  delay(10);
}
