#include "functions.h"

void setup() {

  Serial.begin(9600);

  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(A0, OUTPUT);

  connect(SSID, PASSWORD);

  server.begin();
}

void loop() {
  if (WiFi.status() != WL_CONNECTED) connect(SSID, PASSWORD);
  //Serial.println(digitalRead(button));

  if(Serial.read() == 'i') {
    Serial.print("Local IP : ");
    Serial.println(WiFi.localIP());
    printPublicIP();
  }

  clientobj = server.available();
  if (clientobj) {
    updateStates(getData());

    clientobj.print(ControlPage());
    delay(100);
    clientobj.stop();
  }
}