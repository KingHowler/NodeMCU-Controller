#include <ESP8266WiFi.h>

WiFiServer server(80);
WiFiClient clientobj;

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

#define SSID "my_wifi"
#define PASSWORD "my_password"

#define wifi_led 2

String commands[2];

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


  clientobj = server.available();
  if(Serial.read() == 'i') {
    Serial.print("Local IP : ");
    Serial.println(WiFi.localIP());
  }
  if (clientobj) {
    String request = clientobj.readStringUntil('\n');
    Serial.println(request);
    int l = request.length();
    Serial.println("String length : " + String(l));


    String data = request.substring(5, l - 9);
    Serial.println("DATA Recieved : " + data);
    Serial.println();

    int slashIndex = data.indexOf('/');

    commands[0] = data.substring(0, slashIndex);
    commands[1] = data.substring(slashIndex + 1);

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



    String response = "HTTP/1.1 200 OK\r\n Content-type/html\r\n\r\n";
    response += "<!DOCTYPE html>";
    response += "<html lang=\"en\">";
    response += "<head>";
    response += "<meta charset=\"UTF-8\">";
    response += "<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">";
    response += "<title>NodeMCU Controller</title>";
    response += "<style>";
    response += "body {";
    response += "    font-family: 'Segoe UI', Tahoma, Geneva, Verdana, sans-serif;";
    response += "    display: flex;";
    response += "    justify-content: center;";
    response += "    align-items: center;";
    response += "    height: 100vh;";
    response += "    padding-top: 0%;";
    response += "    background-color: #f0f2f5;";
    response += "    margin: 0;";
    response += "}";
    response += ".container {";
    response += "    text-align: center;";
    response += "}";
    response += ".button-container {";
    response += "    display: grid;";
    response += "    grid-template-columns: repeat(4, 1fr);";
    response += "    gap: 15px;";
    response += "    max-width: 800px;";
    response += "    margin: 20px auto;";
    response += "}";
    response += ".button-container button {";
    response += "    display: flex;";
    response += "    align-items: center;";
    response += "    justify-content: center;";
    response += "    position: relative;";
    response += "    background-color: #007bff;";
    response += "    border: none;";
    response += "    border-radius: 8px;";
    response += "    color: white;";
    response += "    font-size: 16px;";
    response += "    padding: 0 24px;";
    response += "    cursor: pointer;";
    response += "    transition: background-color 0.3s, transform 0.3s;";
    response += "    width: 100%;";
    response += "    height: 40px;";
    response += "    overflow: hidden;";
    response += "    box-sizing: border-box;";
    response += "}";
    response += ".button-container button:hover {";
    response += "    background-color: #0056b3;";
    response += "    transform: scale(1.05);";
    response += "}";
    response += ".button-container button:focus {";
    response += "    outline: none;";
    response += "    box-shadow: 0 0 0 3px rgba(38, 143, 255, 0.5);";
    response += "}";
    response += ".button-label {";
    response += "    flex: 1;";
    response += "    text-align: left;";
    response += "    padding-left: 10px;";
    response += "}";
    response += ".indicator {";
    response += "    position: absolute;";
    response += "    top: 0;";
    response += "    right: 0;";
    response += "    width: 40px;";
    response += "    height: 40px;";
    response += "    border-top-left-radius: 0;";
    response += "    border-top-right-radius: 8px;";
    response += "    border-bottom-right-radius: 8px;";
    response += "    border-bottom-left-radius: 0;";
    response += "    background-color: red;";
    response += "}";
    response += "h1 {";
    response += "    color: #333;";
    response += "    margin-bottom: 20px;";
    response += "}";
    response += "@media (max-width: 600px) {";
    response += "    .button-container {";
    response += "        display: grid;";
    response += "        grid-template-columns: repeat(1, 150px);";
    response += "        grid-template-rows: repeat(12, 1fr);";
    response += "        justify-content: center;";
    response += "        align-items: center;";
    response += "        max-width: 100%;";
    response += "        margin: 0 auto;";
    response += "        padding-top: 10%;";
    response += "    }";
    response += "    .button-container button {";
    response += "        width: 150px;";
    response += "    }";
    response += "}";
    response += "@media (max-width: 350px) {";
    response += "    body {";
    response += "        padding-top: 15%;";
    response += "    }";
    response += "}";
    response += "@media (max-width: 270px) {";
    response += "    body {";
    response += "        padding-top: 30%;";
    response += "    }";
    response += "}";
    response += "</style>";
    response += "</head>";
    response += "<body>";
    response += "<div class=\"container\">";
    response += "<h1>NodeMCU Digital Output Controller</h1>";
    response += "<div class=\"button-container\">";
    if (D0S == false) {
      response += "<button data-base=\"D0\"><span class=\"button-label\">D0</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D0\"><span class=\"button-label\">D0</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (D1S == false) {
      response += "<button data-base=\"D1\"><span class=\"button-label\">D1</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D1\"><span class=\"button-label\">D1</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (D2S == false) {
      response += "<button data-base=\"D2\"><span class=\"button-label\">D2</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D2\"><span class=\"button-label\">D2</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (D3S == false) {
      response += "<button data-base=\"D3\"><span class=\"button-label\">D3</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D3\"><span class=\"button-label\">D3</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (D4S == false) {
      response += "<button data-base=\"D4\"><span class=\"button-label\">D4</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D4\"><span class=\"button-label\">D4</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (D5S == false) {
      response += "<button data-base=\"D5\"><span class=\"button-label\">D5</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D5\"><span class=\"button-label\">D5</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (D6S == false) {
      response += "<button data-base=\"D6\"><span class=\"button-label\">D6</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D6\"><span class=\"button-label\">D6</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (D7S == false) {
      response += "<button data-base=\"D7\"><span class=\"button-label\">D7</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D7\"><span class=\"button-label\">D7</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (D8S == false) {
      response += "<button data-base=\"D8\"><span class=\"button-label\">D8</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"D8\"><span class=\"button-label\">D8</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    if (A0S == false) {
      response += "<button data-base=\"A0\"><span class=\"button-label\">A0</span><div class=\"indicator\" style=\"background-color: red;\"></div></button>";
    } else {
      response += "<button data-base=\"A0\"><span class=\"button-label\">A0</span><div class=\"indicator\" style=\"background-color: lime;\"></div></button>";
    }
    response += "</div>";
    response += "</div>";
    response += "<script>";
    response += "document.querySelectorAll('.button-container button').forEach(button => {";
    response += "    button.addEventListener('click', () => {";
    response += "        const indicator = button.querySelector('.indicator');";
    response += "        const base = button.getAttribute('data-base');";
    response += "        const color = window.getComputedStyle(indicator).backgroundColor;";
    response += "        const suffix = color === 'rgb(0, 255, 0)' ? '0' : '1';";
    response += "        window.location.href = `/${base}/${suffix}`;";
    response += "    });";
    response += "});";
    response += "</script>";
    response += "</body>";
    response += "</html>";


    clientobj.print(response);
    delay(100);
    clientobj.stop();

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
}
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