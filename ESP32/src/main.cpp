#include "secrets.h"
#include <WiFiClientSecure.h>
#include <MQTTClient.h>
#include <ArduinoJson.h>
#include "WiFi.h"

// The MQTT topics that this device should publish/subscribe
#define AWS_IOT_PUBLISH_TOPIC "esp32/pub"
#define AWS_IOT_SUBSCRIBE_TOPIC "esp32/sub"
#define PORT 8883

WiFiClientSecure wifiClient = WiFiClientSecure();
MQTTClient mqttClient = MQTTClient(256);

void messageHandler(String &topic, String &payload)
{
  Serial.println("incoming: " + topic + " - " + payload);

  //  StaticJsonDocument<200> doc;
  //  deserializeJson(doc, payload);
  //  const char* message = doc["message"];
}

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

// Connect to the AWS MQTT message broker
void connect_AWS_IoT_Core()
{
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

void publishMessage()
{
  StaticJsonDocument<200> jsonDoc;
  jsonDoc["time"] = millis();
  jsonDoc["sensor_a0"] = analogRead(0);
  char jsonBuffer[512];
  serializeJson(jsonDoc, jsonBuffer); // print to client

  mqttClient.publish(AWS_IOT_PUBLISH_TOPIC, jsonBuffer);
}

void setup()
{
  // Initialise the serial port
  Serial.begin(115200);

  connect_wifi();

  // Create a message handler
  mqttClient.onMessage(messageHandler);

  connect_AWS_IoT_Core();
}

void loop()
{
  publishMessage();
  mqttClient.loop();
  delay(1000);
}