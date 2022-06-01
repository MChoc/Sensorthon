// Create a secrets.h file in this folder either by
// renaming this file or copying and fill in the blanks.
// The certificates are equivalent to those from
// /Workshop/2. Device Registration/Certificates.png
#include <Arduino.h>
#include <pgmspace.h>

#define SECRET
// THINGNAME should be in the format EduKit_TEAMNAME
// where TEAMNAME is the name of your team you used to register
static const String THINGNAME = "EduKit_TEAMNAME";
static const String AWS_IOT_PUBLISH_TOPIC_THING = THINGNAME + "/pub";
static const String AWS_IOT_SUBSCRIBE_TOPIC_THING = THINGNAME +  "/sub";

// Fill in your wifi settings here
const char WIFI_SSID[] = "";
const char WIFI_PASSWORD[] = "";
const char AWS_IOT_ENDPOINT[] = "a2fk4jnz30nap8-ats.iot.ap-southeast-2.amazonaws.com";

// Fill in the below by copying the contents
// of the keys you downloaded in Workshop 2. 
// It is important to KEEP the
// -----BEGIN CERTIFICATE----- and -----END CERTIFICATE-----

// Copy the contents of AmazonRootCA1.cer
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
COPY_YOUR_KEY_HERE
-----END CERTIFICATE-----
)EOF";

// Copy the contents of device_cert.crt
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
COPY_YOUR_KEY_HERE
-----END CERTIFICATE-----
)KEY";

// Copy the contents of private.key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
COPY_YOUR_KEY_HERE
-----END RSA PRIVATE KEY-----
)KEY";
