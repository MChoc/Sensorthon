#include <Arduino.h>
#include <M5Core2.h>

#define ADCPIN 36 // Analogue to Digital, Yellow Edukit Cable 
#define DACPIN 26 // Digital to Analogue, White Edukit Cable

int flameValue;

void setup() {
  // put your setup code here, to run once:
  pinMode(DACPIN, INPUT); // Set pin 26 to input mode.
  pinMode(ADCPIN, INPUT); // Set pin 36 to input mode.  
  M5.begin(true, true, true, true);
  Serial.begin(115200);

  Serial.println("Successfully Initialised Edukit and Monitor");
  Serial.println("Testing Flame Sensor Sensitivity");

  M5.Lcd("Device has successfully setup, ready for detection");
  M5.Lcd.clearDisplay();
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1000);

  flameValue = analogRead(ADCPIN);

  Serial.printf("%0.i \n", flameValue);

  if (!flameValue) {
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
    M5.Lcd.printf("Analog Value = %.0i", flameValue); 
    if (flameValue > 850) { // TODO: Change this value according to your smoke sensor
      M5.Lcd.setCursor(0,50);
      M5.Lcd.printf("Flame Has been detected");
    }
    else {
      M5.Lcd.setCursor(0,50);
      M5.Lcd.print(" ");
    }
  }

}