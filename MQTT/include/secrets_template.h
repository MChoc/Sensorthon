// Create your own secrets.h in this folder and fill in the blanks.
// The certificates are equivalent to those from
// /Workshop/2. Device Registration/Certificates.png
#include <Arduino.h>
#include <pgmspace.h>

#define SECRET
// THINGNAME should be in the format EduKit_TEAMNAME
// where TEAMNAME is the name of your team
static const String THINGNAME = "EduKit_TEAMNAME";
static const String AWS_IOT_PUBLISH_TOPIC_THING = THINGNAME + "/pub";
static const String AWS_IOT_SUBSCRIBE_TOPIC_THING = THINGNAME +  "/sub";

// Fill in your wifi settings here
const char WIFI_SSID[] = "";
const char WIFI_PASSWORD[] = "";
const char AWS_IOT_ENDPOINT[] = "a2fk4jnz30nap8-ats.iot.ap-southeast-2.amazonaws.com";

// AmazonRootCA1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)EOF";

// device_cert
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)KEY";

// private
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
-----END RSA PRIVATE KEY-----
)KEY";
