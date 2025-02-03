#include <WiFi.h>
#include <HTTPClient.h>;
#include <ArduinoJson.h>;

const char* ssid = ""; // Your wifi name here
const char* password = ""; // Your wifi password here

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("Configuring access point...");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println("Conectado");
  Serial.println(WiFi.localIP());
  Serial.println("");
}

void loop() {
  String apiUrl = "" // Your api url

  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient client;

    client.begin(apiUrl);
    
    int httpCode = client.GET();

    if (httpCode > 0) {
      String payload = client.getString();
      Serial.println("\nStatuscode: " + String(httpCode));
      Serial.println(payload);
    } else {
      Serial.println("Error on HTTP Request");
      Serial.println("\nStatuscode: " + String(httpCode));
    }

    delay(150);
  }
}
