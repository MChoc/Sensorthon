#include "secrets.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"
#include <M5Core2.h>

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"
#define PORT 8883

WiFiClientSecure wifiClient = WiFiClientSecure();
MQTTClient mqttClient = MQTTClient(256);

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float gyroX = 0.0F;
float gyroY = 0.0F;
float gyroZ = 0.0F;

float pitch = 0.0F;
float roll = 0.0F;
float yaw = 0.0F;

float temp = 0.0F;

// Connect to the specified Wi-Fi network
// Retries every 500
void connect_wifi()
{
  Serial.print("Attempting to connect to SSID: ");
  Serial.print(WIFI_SSID);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
}

void initialise_M5()
{
  M5.begin();
  M5.IMU.Init();
  M5.Lcd.setTextColor(GREEN, BLACK);
  M5.Lcd.setTextSize(2);
}

void messageHandler(String &topic, String &payload)
{
  Serial.println("incoming: " + topic + " - " + payload);

  //  StaticJsonDocument<200> doc;
  //  deserializeJson(doc, payload);
  //  const char* message = doc["message"];
}

// Connect to the AWS MQTT message broker
void connect_AWS_IoT_Core()
{
  // Create a message handler
  mqttClient.onMessage(messageHandler);

  // Configure WiFiClientSecure to use the AWS IoT device credentials
  wifiClient.setCACert(AWS_CERT_CA);
  wifiClient.setCertificate(AWS_CERT_CRT);
  wifiClient.setPrivateKey(AWS_CERT_PRIVATE);

  // Connect to the MQTT broker on AWS
  Serial.print("Attempting to AWS IoT Core message broker at mqtt:\\\\");
  Serial.print(AWS_IOT_ENDPOINT);
  Serial.print(":");
  Serial.println(PORT);

  mqttClient.begin(AWS_IOT_ENDPOINT, PORT, wifiClient);
  while (!mqttClient.connect(THINGNAME)) {
    Serial.print("Failed to connect to AWS IoT Core. Error code = ");
    Serial.print(mqttClient.lastError());
    Serial.println(". Retrying...");
    delay(500);
  }

  Serial.println("Connected to AWS IoT Core!");
  mqttClient.subscribe(AWS_IOT_SUBSCRIBE_TOPIC);
}

void setIMUValues()
{
  // Get accelerometer values
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  M5.Lcd.setCursor(0, 20);
  M5.Lcd.printf("accX,   accY,  accZ");
  M5.Lcd.setCursor(0, 42);
  M5.Lcd.printf("%5.2f  %5.2f  %5.2f G", accX, accY, accZ);

  // Get gryoscope values
  M5.IMU.getGyroData(&gyroX, &gyroY, &gyroZ);
  M5.Lcd.setCursor(0, 70);
  M5.Lcd.printf("gyroX,  gyroY, gryoZ");
  M5.Lcd.setCursor(0, 92);
  M5.Lcd.printf("%6.2f %6.2f%6.2f o/s", gyroX, gyroY, gyroZ);

  // Get spatial values
  M5.IMU.getAhrsData(&pitch, &roll, &yaw);
  M5.Lcd.setCursor(0, 120);
  M5.Lcd.printf("pitch,  roll,  yaw");
  M5.Lcd.setCursor(0, 142);
  M5.Lcd.printf("%5.2f %5.2f  %5.2f deg", pitch, roll, yaw);

  // Get temperature value
  M5.IMU.getTempData(&temp);
  M5.Lcd.setCursor(0, 175);
  M5.Lcd.printf("Temperature : %.2f C", temp);
}

void publishMessage()
{
  setIMUValues();

  StaticJsonDocument<200> jsonDoc;
  jsonDoc["time"] = millis();
  jsonDoc["accX"] = accX;
  jsonDoc["accY"] = accY;
  jsonDoc["accZ"] = accZ;
  jsonDoc["gyroX"] = gyroX;
  jsonDoc["gyroY"] = gyroY;
  jsonDoc["gyroZ"] = gyroZ;
  jsonDoc["pitch"] = pitch;
  jsonDoc["roll"] = roll;
  jsonDoc["yaw"] = yaw;
  jsonDoc["temp"] = temp;
  char jsonBuffer[512];
  serializeJson(jsonDoc, jsonBuffer); // print to client

  mqttClient.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void setup()
{
  // Initialise the serial port
  Serial.begin(115200);

  initialise_M5();
  connect_wifi();
  connect_AWS_IoT_Core();
}

void loop()
{
  publishMessage();
  mqttClient.loop();
  delay(5000);
}