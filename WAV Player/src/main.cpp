#include <M5Core2.h>
#include <driver/i2s.h>
#include <WiFi.h>
#include "AudioFileSourceSD.h"
#include "AudioFileSourceID3.h"
#include "AudioGeneratorWAV.h"
#include "AudioOutputI2S.h"
#include <SD.h>

AudioGeneratorWAV *wav;
AudioFileSourceSD *file;
AudioOutputI2S *out;
AudioFileSourceID3 *id3;

#define OUTPUT_GAIN 10

void setup()
{
    M5.begin();

    // Enable speaker
    M5.Axp.SetSpkEnable(true);

    // Initialise SD Card slot
    if (!SD.begin())
    {
        M5.Lcd.println("Card failed, or not present");
        while (1)
            ;
    }
    M5.Lcd.println("SD card initialized.");
    if (SD.exists("/NyanCat.mp3"))
    {
        M5.Lcd.println("NyanCat.mp3 exists.");
    }
    else
    {
        M5.Lcd.println("NyanCat.mp3 doesn't exist.");
    }

    M5.Lcd.setTextFont(2);
    M5.Lcd.printf("Sample MP3 playback begins...\n");

    // Load wave file
    file = new AudioFileSourceSD("/NyanCat.wav");
    
    // Strip ID3 metadata
    id3 = new AudioFileSourceID3(file);

    // Set speaker output port and mode
    out = new AudioOutputI2S(0, 0);
    out->SetPinout(12, 0, 2);
    out->SetOutputModeMono(true);
    out->SetGain((float)OUTPUT_GAIN / 100.0);
    wav = new AudioGeneratorWAV();
    wav->begin(id3, out);
}

void loop()
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
        Serial.printf("WAV done\n");
        delay(1000);
    }
}