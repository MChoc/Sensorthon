#include <Arduino.h>
#include <M5Core2.h>
#include <FastLED.h>

#define NUM_LEDS 10
#define LED_PINS 25

CRGB leds[NUM_LEDS];

uint8_t hue = 0;

int sensor = 26;              // the pin that the sensor is atteched to
int state = LOW;             // by default, no motion detected
int val = 0;                 // variable to store the sensor status (value)

void setup() {
  pinMode(sensor, INPUT);    // initialize sensor as an input
  M5.begin(true, true, true, true); // Init M5Core2.
  Serial.begin(115200);
  FastLED.addLeds<NEOPIXEL, LED_PINS>(leds, NUM_LEDS);
  Serial.println(F("Testing Motion Sensor"));
  M5.Lcd.print("Device successfully hit setup");
}

void loop(){
  delay(500);
  val = digitalRead(sensor);   // read sensor value
  if (val == HIGH) {            // if motion detected
    M5.Lcd.setCursor(0,0);
    Serial.println("Hey I got you!!!");
    M5.Lcd.setTextSize(2);
    M5.Lcd.println("Hey We got you!!!");
    M5.Axp.SetLed(true);
    FastLED.showColor(CHSV(255, 0, 0));
 } 
  else {
    M5.Lcd.clearDisplay();
    Serial.println("Hey where did you go?");
    M5.Axp.SetLed(false);
    FastLED.clear();
 }
}