// MotionLightIoT.ino

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// WiFi settings
const char* ssid = "your_ssid";
const char* password = "your_password";

// MQTT settings
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* mqtt_topic = "motion/light";

WiFiClient espClient;
PubSubClient client(espClient);

// Motion sensor pin
const int motionSensorPin = D1;

void setup() {
  pinMode(motionSensorPin, INPUT);
  Serial.begin(115200);
  setupWiFi();
  client.setServer(mqtt_server, mqtt_port);
}

void loop() {
  if (!client.connected()) {
    reconnect();
  }
  client.loop();

  // Read motion sensor
  if (digitalRead(motionSensorPin) == HIGH) {
    Serial.println("Motion detected!");
    client.publish(mqtt_topic, "Motion detected.");
    delay(5000); // Avoid multiple triggers
  }
}

void setupWiFi() {
  delay(10);
  // Connect to WiFi
  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("WiFi connected!");
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}