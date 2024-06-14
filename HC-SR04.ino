#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>

#define TRIG_PIN 5  // D1 on NodeMCU
#define ECHO_PIN 4  // D2 on NodeMCU

const char* ssid = "Your_WiFi_SSID";
const char* password = "Your_WiFi_Password";
const char* serverName = "http://your_local_server_address/endpoint";

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
}

long readDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  long duration = pulseIn(ECHO_PIN, HIGH);
  long distance = (duration * 0.034) / 2;
  return distance;
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;

    long distance = readDistance();
    Serial.print("Distance: ");
    Serial.println(distance);

    http.begin(serverName);
    http.addHeader("Content-Type", "application/json");

    String jsonPayload = "{\"distance\":" + String(distance) + "}";
    int httpResponseCode = http.POST(jsonPayload);

    if (httpResponseCode > 0) {
      String response = http.getString();
      Serial.println(httpResponseCode);
      Serial.println(response);
    } else {
      Serial.println("Error on sending POST: ");
      Serial.println(httpResponseCode);
    }
    http.end();
  } else {
    Serial.println("WiFi Disconnected");
  }

  delay(10000);  // Delay 10 seconds
}
