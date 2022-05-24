#include <pgmspace.h>

#define SECRET
#define THINGNAME ""

// const char WIFI_SSID[] = "MobileAnywhere";
// const char WIFI_PASSWORD[] = "tF7Vvg6hj=1~";

const char WIFI_SSID[] = "OPTUS_385454";
const char WIFI_PASSWORD[] = "gemmymiffy66521";
const char AWS_IOT_ENDPOINT[] = "a32fszd62t1lta-ats.iot.ap-southeast-2.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAIHr1608ghynxJkDtDppqyFn+cVFMA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yMjA1MTcxMTM4
NTBaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCdTh6ZEBjks2UOGKgw
l82Ee32rmQZUORjtv0CjGRRjaYSOqfTEw0mOG7Fm46eef7kxfLiNZvw9lwYgoOVN
ANrEzS32QsstfhAnpoP1ggvQoKmlnJKMUsXrvsm4FRfO5KB35d26Cpg6alEH3osR
tGBm7AZt4k+U/ZmEz5SFssWg9VIPB0x2vq1qzs0KMENSPM3L4XF2QtKvgoIbUOY7
DIe0LeaqGbb/J7YSo25kqSk1I4h69ryZQd5zI5G/8VF1+P5CMdPYRDyy6/uB4iTF
0XVtqpp3C/TT54N/ahBpY+0Y+fXbqwF+cuFQ/LKFvzcTIbqxi+nAB1RckMBbwuO0
UEnpAgMBAAGjYDBeMB8GA1UdIwQYMBaAFByIIJqCL3iL9b0yoWNVO3cVHMV0MB0G
A1UdDgQWBBRsvXwDogHBYi1bCoybVNRPDIYItDAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEACxPBGExEkEkfDjHeVCeWJ3wh
t+fP8E3nrsEIur3h2jdmaM5l+p7P7Y3D5XJv1DhTe4pno+4XI9LTs8uQvh6ZMJqK
jkw+Wz95VFxzx8xkGIeaQ3rIcS9xaQvifafiLT2wpPkKUiZSk3llX2a72Qx4Vcqm
aQz6SfOMqhD2pGysGfIHl7I1Kn8rpVh6Hls8hBCrdnlG1l2XULJuhFvUbwmJ1SAL
V/ANko3Xmq9hbFe7IJPGRCzpyoAVfVOySEPTTgifF5ourt2dN/AiOYJ/FjCi9lzF
6gpj74HqWk7id5HR0XmcMbAKDHvm1ofdX0JxWq6KAuXozlxKbc3v9/KzixPjGw==
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAnU4emRAY5LNlDhioMJfNhHt9q5kGVDkY7b9AoxkUY2mEjqn0
xMNJjhuxZuOnnn+5MXy4jWb8PZcGIKDlTQDaxM0t9kLLLX4QJ6aD9YIL0KCppZyS
jFLF677JuBUXzuSgd+XdugqYOmpRB96LEbRgZuwGbeJPlP2ZhM+UhbLFoPVSDwdM
dr6tas7NCjBDUjzNy+FxdkLSr4KCG1DmOwyHtC3mqhm2/ye2EqNuZKkpNSOIeva8
mUHecyORv/FRdfj+QjHT2EQ8suv7geIkxdF1baqadwv00+eDf2oQaWPtGPn126sB
fnLhUPyyhb83EyG6sYvpwAdUXJDAW8LjtFBJ6QIDAQABAoIBAHDN9YlEDuXqc7xx
GCOIqLuppwwoN26sZ2EOtnZ/ZKyJnaKE5F85wASlfUlQVgKGizKewuW8BYTRSXaa
ivT2eOuKS7x+V59u+HzGn3iuYnSg0idOKZVxQjd1YMieb61RLHXupFtmf5XcafFf
uJDgrgUAmvevw+wPFEk2Zsad1bU/N0jWDDd99uwCQReQbIEyU6uCunoN6dymow86
wDyf8elVpL+x0rzBIQx4UbhuY35zyvMZljGwemY/F1rAMO9x8JVbYwcVmKDYtiL7
cBZdS3i3LODrP8ezBp+gIdCjzZF9MvskwjEjk2vip8sXeeNq24SPNmfSn7MGQwfM
Q+mhOJUCgYEAzftvG2iG8vAkTyKqZBUDoUs0wRj1+Vq8IGWMyQb8n2Sfn32Tr5Cc
d8PAPTCu4snvsTzf303FexT/VjEjJK6DNEIpVEWJYz+o0qkdiUvWXXY1oSO6eM5l
7QDDqLVKqlglmoA4J4yYdmD7iC3QJQJuHBkvmiag0sVWCys3c3ctJCMCgYEAw4DA
8mvTegoZe4ZkUpcXaFtcABGEaQ/rj2KZlIQNeaDjwoGvzQj/rtDe9tPE9W5qLe9C
tmJjNJmW0NUi1hm8EXAelwPhWJWfA9nxAx17CCivT0q+aE2W6AID1RKgENsPEFIe
e+UK8YHKtNxQjCtVjCd91TqJvE67u/iUOIgExIMCgYBzvmduhUvfUyVz+ky4tD43
8iSQpNAC8ANqSOXVSEHH5yjy3AOS0bW6bpqlR6fd9A7mDwjVV8QyJ1hbPH087Xr4
cHz8x54t0OWyiij4r06jcfssswDjRUds59MKB+UO1z06FfZ38r7xNgnhOa0OPtFU
pKpk+nPAO/bfi8c68KrC9QKBgQCteQm8EcFMgLmrycwrHLZAexBfXyvGrcGvMSZl
iecLDaALb1e2700wqVWuXqpdvOOqbqsbeqHcgow4MWb/40Xlkz8RcPf7yoeWu0QI
J5iL3M3x5biehHpq057i6evuCPKM4ND7znivYyOi5/rw5WK7Qi99jLu6w4IBgMjE
gKz6UQKBgQCjYkZP0GaWQZE7tWvkj5gf6D6mQhEqukLREJnF1FQgBmHieodWjijz
NNvQmeluhNjMdCdafltOBaG+AZq+T5VqbiH1CSwy6nJS/en72ut4dQxfQMSX2tbx
JO8LJOTAqrWz5yMt8/4nuQEm7Ln0EfDSwZV+wLdTCJodTnIwn+s6Kg==
-----END RSA PRIVATE KEY-----
)KEY";