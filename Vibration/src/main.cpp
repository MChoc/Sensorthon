#include <Arduino.h>
#include <M5Core2.h>

void setup() {
  M5.begin();
}

void loop() {
  // Library defines 3 as the magic number

  // Turn on vibration for 1000ms
  M5.Axp.SetLDOEnable(3, true);
  delay(1000);

  // Turn off vibration for 1000ms
  M5.Axp.SetLDOEnable(3, false);
  delay(1000);
}