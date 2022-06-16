#include <Arduino.h>
#include <FastLED.h>
#include <M5Core2.h>
#include "animation.h"
#include "AudioFileSourceSD.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"

#define SCALE 3
#define LED_PINS 25
#define NUM_LEDS 10
#define OUTPUT_GAIN 10

CRGB leds[NUM_LEDS];
uint8_t hue = 0;
AudioGeneratorWAV *wav;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;

void rainbowTask(void *pvParameters)
{
  while (1)
  {
    FastLED.showColor(CHSV(hue++, 255, 255));
  }
}

void audioTask(void *pvParameters)
{
  while (1)
  {
    if (wav->isRunning())
    {
      if (!wav->loop())
      {
        wav->stop();
      }
    }
    else
    {
      Serial.println("WAV finished playing");
      wav->stop();
      wav->begin(id3, out);
    }
  }
}

void animationTask(void *pvParameters)
{
  for (int z = 0; z < 12; z++)
  {
    for (int y = 0; y < 64; y++)
    {
      for (int x = 0; x < 64; x++)
      {
        char ch = frames[z][y][x];
        int colour = 0x0000;
        if (ch == ',')
        {
          colour = 0x000B;
        }
        else if (ch == '\'')
        {
          colour = 0x0000;
        }
        else if (ch == '*')
        {
          colour = 0x5ACB;
        }
        else if (ch == '.')
        {
          colour = 0xFFFF;
        }
        else if (ch == '%')
        {
          colour = 0xD435;
        }
        else if (ch == '@')
        {
          colour = 0xFFFA;
        }
        else if (ch == '$')
        {
          colour = 0xD435;
        }
        else if (ch == '-')
        {
          colour = 0xD010;
        }
        else if (ch == '>')
        {
          colour = 0xF800;
        }
        else if (ch == '&')
        {
          colour = 0xFD60;
        }
        else if (ch == '+')
        {
          colour = 0xFFE0;
        }
        else if (ch == '#')
        {
          colour = 0x87E0;
        }
        else if (ch == '=')
        {
          colour = 0x043F;
        }
        else if (ch == ';')
        {
          colour = 0x0015;
        }
        M5.Lcd.fillRect(x * SCALE, y * SCALE, SCALE, SCALE, colour);
      }
    }
  }
}

void initialiseAudio()
{
  // Enable speaker
  M5.Axp.SetSpkEnable(true);

  // Initialise SD card slot
  if (!SD.begin())
  {
    Serial.println("SD card failed to mount or not present");
    while (1)
      ;
  }
  M5.Lcd.println("SD card initialised");

  if (SD.exists("/NyanCat.wav"))
  {
    Serial.println("NyanCat.wav exists");
  }
  else
  {
    Serial.println("NyanCat.wav doesn't exist");
  }

  // Load wav file
  file = new AudioFileSourceSD("/NyanCat.wav");
  id3 = new AudioFileSourceID3(file);
  out = new AudioOutputI2S(0, 0);
  out->SetPinout(12, 0, 2);
  out->SetOutputModeMono(true);
  out->SetGain((float)OUTPUT_GAIN / 100.0);
  wav = new AudioGeneratorWAV();
  wav->begin(id3, out);
}

void setup()
{
  Serial.begin(115200);
  M5.begin();

  initialiseAudio();

  // Specify LED pins
  FastLED.addLeds<SK6812, LED_PINS>(leds, NUM_LEDS);

  // Create tasks that be run in parallel
  xTaskCreatePinnedToCore(rainbowTask, "rainbow", 4096, NULL, 1, NULL, 0);
  // xTaskCreatePinnedToCore(animationTask, "animation", 4096, NULL, 3, NULL, 0);
}

void loop()
{
  audioTask(NULL);
}