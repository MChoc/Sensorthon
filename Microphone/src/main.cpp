#include <Arduino.h>
#include <M5Core2.h>
#include <driver/i2s.h>

#define CONFIG_I2S_BCK_PIN 12
#define CONFIG_I2S_LRCK_PIN 0
#define CONFIG_I2S_DATA_PIN 2
#define CONFIG_I2S_DATA_IN_PIN 34

#define SPEAKER_I2S_NUMBER I2S_NUM_0

#define MODE_MIC 0
#define MODE_SPEAKER 1
#define DATA_SIZE 1024

#define SAMPLE_RATE 44100
#define BITS_PER_SAMPLE I2S_BITS_PER_SAMPLE_16BIT

uint8_t microphoneData[DATA_SIZE * 100];
int data_offset = 0;

bool SpeakerOrMicInit(int mode)
{
  esp_err_t err = ESP_OK;

  // Uninstall the current sound driver
  i2s_driver_uninstall(SPEAKER_I2S_NUMBER);

  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER),
    .sample_rate = SAMPLE_RATE,                   // Sample rate in Hz
    .bits_per_sample = BITS_PER_SAMPLE,           // Sample rate in bits
    .channel_format = I2S_CHANNEL_FMT_ONLY_RIGHT, // Channel format
    .communication_format = I2S_COMM_FORMAT_I2S,  // Communication format/protocol
    .intr_alloc_flags = ESP_INTR_FLAG_LEVEL1,     // Interrupt level
    .dma_buf_count = 2,                           // Direct memory access buffer
    .dma_buf_len = 128,                           // Direct memory access length
  };

  // Install microphone or speaker driver settings
  if (mode == MODE_MIC)
  {
    i2s_config.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_RX | I2S_MODE_PDM);
  }
  else
  {
    i2s_config.mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX);
    i2s_config.use_apll = false;
    i2s_config.tx_desc_auto_clear = true;
  }
  err += i2s_driver_install(SPEAKER_I2S_NUMBER, &i2s_config, 0, NULL);

  // Set sound pins and clock
  i2s_pin_config_t tx_pin_config;
  tx_pin_config.bck_io_num = CONFIG_I2S_BCK_PIN;
  tx_pin_config.ws_io_num = CONFIG_I2S_LRCK_PIN;
  tx_pin_config.data_out_num = CONFIG_I2S_DATA_PIN;
  tx_pin_config.data_in_num = CONFIG_I2S_DATA_IN_PIN;
  err += i2s_set_pin(SPEAKER_I2S_NUMBER, &tx_pin_config);
  err += i2s_set_clk(SPEAKER_I2S_NUMBER, SAMPLE_RATE, BITS_PER_SAMPLE, I2S_CHANNEL_MONO);

  return true;
}

void M5Init()
{
  // I2C is the 4th option which we need to manually enable
  M5.begin(true, true, true, true);
  
  // Enable microphone
  M5.Axp.SetSpkEnable(true);

  M5.Lcd.fillScreen(WHITE);
  M5.Lcd.setTextColor(RED);
  M5.Lcd.setCursor(10, 10);
  M5.Lcd.printf("Recorder");

  M5.Lcd.setTextColor(BLACK);
  M5.Lcd.setCursor(10, 26);
  M5.Lcd.printf("Press Left Button to record");
}

void setup() {
  M5Init();
}

void loop() {
  TouchPoint_t pos = M5.Touch.getPressPoint();

  if (pos.y > 240) {
    if (pos.x < 109) {
      M5.Axp.SetLDOEnable(3, true);
      delay(100);
      M5.Axp.SetLDOEnable(3, false);

      SpeakerOrMicInit(MODE_MIC);

      // Begin recording
      data_offset = 0;
      size_t byte_read;
      while (1) {
        i2s_read(SPEAKER_I2S_NUMBER, (char *)(microphoneData + data_offset), DATA_SIZE, &byte_read, (100 / portTICK_RATE_MS));
        data_offset += DATA_SIZE;
        if (data_offset == DATA_SIZE * 100 || M5.Touch.ispressed() != true)
          break;
      }

      // Play recording
      size_t bytes_written;
      SpeakerOrMicInit(MODE_SPEAKER);
      i2s_write(SPEAKER_I2S_NUMBER, microphoneData, data_offset, &bytes_written, portMAX_DELAY);
    }
  }
}