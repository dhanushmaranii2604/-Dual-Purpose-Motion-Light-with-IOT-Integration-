// MotionLightAdvanced.ino

#include <WiFi.h>
#include <PubSubClient.h>

// Define manual control pin
const int manualControlPin = 2;
// Define relay pin
const int relayPin = 3;

// WiFi and MQTT settings
const char* ssid = "your_ssid";
const char* password = "your_password";
const char* mqttServer = "mqtt.yourserver.com";
const int mqttPort = 1883;

WiFiClient wifiClient;
PubSubClient mqttClient(wifiClient);

void setup() {
    pinMode(manualControlPin, INPUT);
    pinMode(relayPin, OUTPUT);
    Serial.begin(115200);
    connectToWiFi();
    mqttClient.setServer(mqttServer, mqttPort);
}

void loop() {
    if (!mqttClient.connected()) {
        reconnectMQTT();
    }
    mqttClient.loop();

    // Manual control
    if (digitalRead(manualControlPin) == HIGH) {
        digitalWrite(relayPin, HIGH);
        mqttClient.publish("home/light/status", "ON");
    } else {
        digitalWrite(relayPin, LOW);
        mqttClient.publish("home/light/status", "OFF");
    }
}

void connectToWiFi() {
    delay(10);
    Serial.print("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println(" WiFi connected");
}

void reconnectMQTT() {
    while (!mqttClient.connected()) {
        Serial.print("Connecting to MQTT...");
        if (mqttClient.connect("MotionLightClient")) {
            Serial.println("connected");
        } else {
            Serial.print("failed, rc=");
            Serial.print(mqttClient.state());
            delay(2000);
        }
    }
}