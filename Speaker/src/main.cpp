#include <Arduino.h>
#include <M5Core2.h>
#include <driver/i2s.h>
#include "data.c"

extern const unsigned char previewR[120264];

#define CONFIG_I2S_BCK_PIN 12
#define CONFIG_I2S_LRCK_PIN 0
#define CONFIG_I2S_DATA_PIN 2
#define CONFIG_I2S_DATA_IN_PIN 34

#define Speak_I2S_NUMBER I2S_NUM_0

#define SAMPLE_RATE 44100
#define BITS_PER_SAMPLE I2S_BITS_PER_SAMPLE_16BIT

void I2SSpeakerInit()
{
  esp_err_t err = ESP_OK;

  i2s_config_t i2s_config = {
      .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
      .sample_rate = SAMPLE_RATE,                           // Sample rate in Hz
      .bits_per_sample = BITS_PER_SAMPLE,                   // Sampling rate in bits
      .channel_format = I2S_CHANNEL_FMT_ALL_RIGHT,          // Channel format
      .communication_format = I2S_COMM_FORMAT_I2S,          // Communication format/protocol
      .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,             // Interrupt level
      .dma_buf_count = 2,                                   // Direct memory access buffer
      .dma_buf_len = 128,                                   // Direct memory access length
      .use_apll = false,                                    // Use AAPL clock
      .tx_desc_auto_clear = true,                           // Auto clear tx descriptor if there is underflow

  };

  // Install driver with new settings
  err += i2s_driver_install(Speak_I2S_NUMBER, &i2s_config, 0, NULL);

  // Define pin configuration for speaker and clock
  i2s_pin_config_t tx_pin_config = {
    .bck_io_num = CONFIG_I2S_BCK_PIN,
    .ws_io_num = CONFIG_I2S_LRCK_PIN,
    .data_out_num = CONFIG_I2S_DATA_PIN,
    .data_in_num = CONFIG_I2S_DATA_IN_PIN,

  };
  err += i2s_set_pin(Speak_I2S_NUMBER, &tx_pin_config);
  err += i2s_set_clk(Speak_I2S_NUMBER, SAMPLE_RATE, BITS_PER_SAMPLE, I2S_CHANNEL_MONO);
}

void displayInit()
{
  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.printf("Speaker Test!");
  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(0, 26);
  M5.Lcd.printf("Press Left Button to hear DingDong!");
}

void speakInit()
{
  M5.Axp.SetSpkEnable(true);
  I2SSpeakerInit();
}

// Play the sound by writing via I2S
void dingDong()
{
  size_t btyes_written = 0;
  i2s_write(Speak_I2S_NUMBER, previewR, 120264, &btyes_written, portMAX_DELAY);
}

void setup()
{
  Serial.begin(115200);
  M5.begin(true, true, true, true);
  displayInit();
  speakInit();
  dingDong();
  delay(100);
}

void loop()
{
  TouchPoint_t pos = M5.Touch.getPressPoint();

  if (pos.y > 240)
    if (pos.x < 109)
    {
      M5.Axp.SetLDOEnable(3, true);
      delay(100);
      M5.Axp.SetLDOEnable(3, false);
      dingDong();
    }

  delay(10);
}