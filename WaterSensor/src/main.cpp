#include <Arduino.h>
#include <M5Core2.h>

#define ADCPIN 36 // Analogue to Digital, Yellow Edukit Cable 
#define DACPIN 26 // Digital to Analogue, White Edukit Cable

void setup() {
  bool LCDEnable = true;
  bool SDEnable = true; 
  bool SerialEnable = true;
  bool I2CEnable = true;
  pinMode(DACPIN, INPUT); // Set pin 26 to input mode.
  pinMode(ADCPIN, INPUT); // Set pin 36 to input mode.
  M5.begin(LCDEnable, SDEnable, SerialEnable, I2CEnable); // Init M5Core2.
  Serial.begin(115200);
  Serial.println(F("Testing Water Sensor Test"));
  M5.Lcd.print("Device setup");
  M5.Lcd.clear();
}

void readWaterSensor() {
  if ( digitalRead(ADCPIN) == HIGH) {
      M5.Lcd.clear();
      Serial.println("Water sensor reading: HIGH");
      Serial.println("Water Detected");
      M5.Lcd.setCursor(0,0);
      M5.Lcd.print("Water Reading = HIGH");
      M5.Lcd.setCursor(0,10);
      M5.Lcd.print("Water detected!!!!!!");
      M5.update();
   } else {
      M5.Lcd.clear();
      Serial.println("Water sensor reading: LOW");
      M5.Lcd.setCursor(0,0);
      M5.Lcd.print("Water Reading = LOW");
      M5.Lcd.setCursor(0,10);
      M5.Lcd.print("No Water detected");
      M5.update();
   }
}

void loop() {
  delay(500);

  readWaterSensor();
}