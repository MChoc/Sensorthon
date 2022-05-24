#include <Arduino.h>
#include <M5Core2.h>

void setup() {
  Serial.begin(115200);

  M5.begin();
  M5.Lcd.setCursor(50, 50);
  M5.Lcd.setTextColor(GREEN);
}

void loop() {
  // Read press state of button
  M5.update();

  // Detect if button was released or
  // 1000ms since last press and held for 200ms
  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    M5.Lcd.print('A');
  } else if (M5.BtnB.wasReleased() || M5.BtnB.pressedFor(1000, 200)) {
    M5.Lcd.print('B');
  } else if (M5.BtnC.wasReleased() || M5.BtnC.pressedFor(1000, 200)) {
    // Clear screen if no button was pressed for more than 1000ms
    M5.Lcd.clear(BLACK);
    // Reset cursor
    M5.Lcd.setCursor(50,50);
  }
}