#include <Arduino.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <M5Core2.h>

#include "Wifi.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "arduino_secrets.h"

#define ADCPIN 36
#define DACPIN 26
#define DHTTYPE DHT11

DHT dht(DACPIN, DHTTYPE);
float temp, humid;
int analogReading;
int smokeThreshold = 400;

#define IOT_PUB_TOPIC "sensorExp/publish"
#define IOT_SUB_TOPIC "sensorExp/subscribe"
#define PORT 8883

WiFiClientSecure wifiClient = WiFiClientSecure();
MQTTClient mqttClient = MQTTClient(256);

void wifi_connect() {
  Serial.printf("Connecting to network: %s \n", WIFI_SSID);
  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Connecting");
    delay(1000);
  }

  Serial.println("Successfully connected to wifi network");
}

float dht11(String dataType ) {
  float value;

  if (dataType == "temperature") {
    value = dht.readTemperature();
  }
  else {
    value = dht.readHumidity();
  }
  return value;
}

void displayValues(float temp, float humid, int analogReading) {
  Serial.println("Printing readings now:");

  M5.Lcd.setCursor(0,0);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("Temperature = %.2fC", temp);

  M5.Lcd.setCursor(0,50);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("Humidity = %.0f", humid);

  M5.Lcd.setCursor(0,100);
  M5.Lcd.setTextSize(2);
  M5.Lcd.printf("Analog Value = %.0i", analogReading);

  M5.update(); //Update M5Stack Core2
}

void setup() {
  pinMode(DACPIN, INPUT); // Set pin 26 to input mode.
  pinMode(ADCPIN, INPUT); // Set pin 36 to input mode.
  M5.begin(true, true, true, true); // Init M5Core2.
  dht.begin();
  Serial.begin(115200);
  Serial.println(F("Testing DHT 11 and Analog Sensor Connection"));
  M5.Lcd.print("Device successfully hit setup");
  M5.Lcd.clear();
}

void loop() {
  delay(1000);
  temp = dht11("temperature");
  humid = dht11("humidity");

  Serial.printf("%.2f degrees\n%.0f \n", temp, humid);

  // analogReading = analogRead(ADCPIN);

  // Serial.printf("%.0i \n", analogReading);

  // int waterDetection = digitalRead(DACPIN);

  if ( digitalRead(ADCPIN) == HIGH) {
      M5.Lcd.clear();
      Serial.println("Water sensor reading: HIGH");
      Serial.println("Water Detected");
      M5.Lcd.setCursor(0,100);
      M5.Lcd.setTextSize(2);
      M5.Lcd.print("Water Reading = HIGH");
      M5.Lcd.print("Water detected!!!!!!");
      M5.update();
   } else {
      M5.Lcd.clear();
      Serial.println("Water sensor reading: LOW");
      M5.Lcd.setCursor(0,100);
      M5.Lcd.setTextSize(2);
      M5.Lcd.print("Water Reading = HIGH");
      M5.update();
   }

  //If reading errors and needs to exit early to reread
  if (isnan(temp) || isnan(humid)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    M5.Lcd.clear(); 
    M5.Lcd.setCursor(0,0);
    M5.Lcd.setTextSize(2);
    M5.Lcd.print("Unable to fetch temp/humidity readings, trying again");
    M5.update(); //Update M5Stack Core2
    return;
  }
  else {
    M5.Lcd.clear(); 
  }

  // if (analogReading < 150 || analogReading > 900) { // Smoke sensor threshold values for false readings
  // if (!analogReading) {
  //   Serial.println(F("Failed to read from the analog sensor"));
  //   M5.Lcd.clear(); 
  //   M5.Lcd.setCursor(0,0);
  //   M5.Lcd.setTextSize(2);
  //   M5.Lcd.print("Unable to find analog readings, trying again");
  //   M5.update(); //Update M5Stack Core2
  //   return;
  // }
  // else {
  //   M5.Lcd.clear(); 
  // }

  displayValues(temp, humid, analogReading);
}