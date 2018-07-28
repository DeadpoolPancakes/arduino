#include <DHT.h>
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>




const char* ssid = "";
const char* password = "";

ESP8266WebServer server(80);

#define DHTPIN 0  // what pin we're connected to
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

const int led = 13;
int ldr = A0;
int datapin = 0;
int dhtpos = 4;
int dhtneg = 5;
float hum;  //Stores humidity value
float temp; //Stores temperature value
int val = 0;


void handleRoot() {
  digitalWrite(led, 1);
  server.send(200, "text/plain", "hello from esp8266!");
  digitalWrite(led, 0);
}

void gettemp() {
  digitalWrite(dhtpos, HIGH);
  digitalWrite(dhtneg, LOW);
  temp = dht.readTemperature();
  Serial.println(temp);
  server.send(200, "text/plain", String(temp));
}

void gethum(){
  digitalWrite(dhtpos, HIGH);
  digitalWrite(dhtneg, LOW);
  hum = dht.readHumidity();
  Serial.println(hum);
  server.send(200, "text/plain", String(hum));
}

void getlight() {
  digitalWrite(led, 1);
  val = analogRead(ldr);
  server.send(200, "text/plain", String(val));
  digitalWrite(led, 0);
}


void handleNotFound(){
  digitalWrite(led, 1);
  String message = "File Not Found\n\n";
  message += "URI: ";
  message += server.uri();
  message += "\nMethod: ";
  message += (server.method() == HTTP_GET)?"GET":"POST";
  message += "\nArguments: ";
  message += server.args();
  message += "\n";
  for (uint8_t i=0; i<server.args(); i++){
    message += " " + server.argName(i) + ": " + server.arg(i) + "\n";
  }
  server.send(404, "text/plain", message);
  digitalWrite(led, 0);
}

void setup(void){
  pinMode(led, OUTPUT);
  pinMode(dhtpos, OUTPUT);
  pinMode(dhtneg, OUTPUT);

  digitalWrite(led, 0);
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  if (MDNS.begin("esp8266")) {
    Serial.println("MDNS responder started");
  }

  server.on("/", handleRoot);
  server.on("/temp", gettemp);
  server.on("/light", getlight);
  server.on("/humidity", gethum);

  server.on("/inline", [](){
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  server.begin();
  Serial.println("HTTP server started");
}

void loop(void){
  server.handleClient();
}
