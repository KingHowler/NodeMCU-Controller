#pragma once

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

WiFiServer server(80);
WiFiClient clientobj;

#define SSID "Guest"
#define PASSWORD "thePortal"

#define wifi_led 2

String commands[2];


bool D0S = false;
bool D1S = false;
bool D2S = false;
bool D3S = false;
bool D4S = false;
bool D5S = false;
bool D6S = false;
bool D7S = false;
bool D8S = false;
bool A0S = false;