#include <Arduino.h>
#include <M5Core2.h>

#define ADCPIN 36
#define DACPIN 26

int analogReading;
int smokeThreshold = 400;

void setup() {
  pinMode(DACPIN, INPUT); // Set pin 26 to input mode.
  pinMode(ADCPIN, INPUT); // Set pin 36 to input mode.
  M5.begin(true, true, true, true); // Init M5Core2.
  Serial.begin(115200);
  M5.Lcd.print("Device successfully hit setup");
  M5.Lcd.print("Delaying for device to warm up readings");
  // delay(600000);
  M5.Lcd.clear();
}

void loop() {
  delay(1000);

  analogReading = analogRead(ADCPIN);
  // analogReading = analogRead(DACPIN);


  Serial.printf("%.0i \n", analogReading);

  // if (analogReading > 1300 || analogReading < 900) { // Idle Upper and lower limit of smoke sensor after warmed
  if (!analogReading) {
    Serial.println(F("Failed to read from the analog sensor"));
    M5.Lcd.clear(); 
    M5.Lcd.setCursor(0,0);
    M5.Lcd.setTextSize(2);
    M5.Lcd.print("Unable to find analog readings, trying again");
    M5.update(); //Update M5Stack Core2
    return;
  }
  else {
    M5.Lcd.clear();
    M5.Lcd.setCursor(0,0);
    M5.Lcd.setTextSize(2);
    M5.Lcd.printf("Analog Value = %.0i", analogReading); 
    if (analogReading > 850) { // TODO: Change this value according to your smoke sensor
      M5.Lcd.setCursor(0,50);
      M5.Lcd.printf("Smoke Has been detected");
    }
    else {
      M5.Lcd.setCursor(0,50);
      M5.Lcd.print(" ");
    }
  }
}