#pragma once
#include "pages.h"
#include "global-variables.h"

void connect(String ssid,String pass){
    WiFi.begin(SSID, PASSWORD);
  Serial.println("Trying to CONNECT to WIFI");
  while (WiFi.status() != WL_CONNECTED) {
    digitalWrite(wifi_led, HIGH);
    delay(250);
    Serial.print(" . ");
    digitalWrite(wifi_led, LOW);
    delay(250);
  }
  Serial.println("Connected successfully!");
  digitalWrite(wifi_led, LOW);
    
  Serial.print("Local IP : ");
  Serial.println(WiFi.localIP());
}

void printPublicIP() {
  // Create a WiFiClient object
  WiFiClient client;

  // Create an HTTPClient object
  HTTPClient http;

  // Start the connection to the web server
  http.begin(client, "http://api.ipify.org"); // Pass the WiFiClient and the URL

  int httpCode = http.GET();

  if (httpCode > 0) {
    String payload = http.getString();
    Serial.print("Public IP Address: ");
    Serial.println(payload);
  } else {
    Serial.println("Error getting IP address");
  }

  http.end();
}

String getData() {
  String request = clientobj.readStringUntil('\n');
  Serial.println(request);
  int l = request.length();
  Serial.println("String length : " + String(l));
  
  String data = request.substring(5, l - 9);
  Serial.println("DATA Recieved : " + data);
  Serial.println();
  return data;
}

void updateStates(String ChangedState) {
  int slashIndex = ChangedState.indexOf('/');

  commands[0] = ChangedState.substring(0, slashIndex);
  commands[1] = ChangedState.substring(slashIndex + 1);

  Serial.println("Pin : " + commands[0]);
  Serial.println("State : " + commands[1]);
  Serial.println();

  if (commands[0] == "D0") { D0S = commands[1].toInt(); }
  if (commands[0] == "D1") { D1S = commands[1].toInt(); }
  if (commands[0] == "D2") { D2S = commands[1].toInt(); }
  if (commands[0] == "D3") { D3S = commands[1].toInt(); }
  if (commands[0] == "D4") { D4S = commands[1].toInt(); }
  if (commands[0] == "D5") { D5S = commands[1].toInt(); }
  if (commands[0] == "D6") { D6S = commands[1].toInt(); }
  if (commands[0] == "D7") { D7S = commands[1].toInt(); }
  if (commands[0] == "D8") { D8S = commands[1].toInt(); }
  if (commands[0] == "A0") { A0S = commands[1].toInt(); }

  digitalWrite(D0, D0S);
  digitalWrite(D1, D1S);
  digitalWrite(D2, D2S);
  digitalWrite(D3, D3S);
  digitalWrite(D4, D4S);
  digitalWrite(D5, D5S);
  digitalWrite(D6, D6S);
  digitalWrite(D7, D7S);
  digitalWrite(D8, D8S);
  digitalWrite(A0, A0S);
}