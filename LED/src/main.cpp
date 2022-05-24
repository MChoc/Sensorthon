#include <Arduino.h>
#include <M5Core2.h>
#include <FastLED.h>

#define NUM_LEDS 10
#define LED_PINS 25

CRGB leds[NUM_LEDS];

uint8_t hue = 0;

void blinkLED()
{
  // Turn LED on for 1000ms
  M5.Axp.SetLed(true);
  delay(50);

  // Turn LED off for 1000ms
  M5.Axp.SetLed(false);
  delay(50);
}

void rainbowSetup()
{
  // Initialise and assign pins to LED
  FastLED.addLeds<NEOPIXEL, LED_PINS>(leds, NUM_LEDS);
}

void rainbowLoop()
{
  // Loop through the rainbow
  FastLED.showColor(CHSV(hue++, 255, 255));
}

void setup()
{
  Serial.begin(115200);
  M5.begin();
  rainbowSetup();
}

void loop()
{
  blinkLED();
  rainbowLoop();
}