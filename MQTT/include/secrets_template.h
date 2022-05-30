// Create your own secrets.h in this folder and fill in the blanks.
// The certificates are equivalent to those from
// /Workshop/2. Device Registration/Certificates.png
#include <pgmspace.h>

// THINGNAME should be in the format EduKit_TEAMNAME
// where TEAMNAME is the name of your team
#define THINGNAME ""
#define SECRET

const char WIFI_SSID[] = "";
const char WIFI_PASSWORD[] = "";
const char AWS_IOT_ENDPOINT[] = "";

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
