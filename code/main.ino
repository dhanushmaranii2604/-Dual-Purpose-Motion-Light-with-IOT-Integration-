// Dual-Purpose Motion Light Control Code

#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// WiFi and MQTT parameters
const char* ssid = "your_SSID";
const char* password = "your_PASSWORD";
const char* mqtt_server = "your_MQTT_SERVER";

WiFiClient espClient;
PubSubClient client(espClient);

// Function declarations
void setupWiFi();
void callback(char* topic, byte* message, unsigned int length);
void reconnect();
void setup();
void loop();

void setupWiFi() {
    delay(10);
    // Connect to WiFi
    Serial.println("Connecting to WiFi...");
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("Connected to WiFi");
}

void callback(char* topic, byte* message, unsigned int length) {
    // Handle incoming messages
    String msg;
    for (int i = 0; i < length; i++) {
        msg += (char)message[i];
    }
    Serial.println("Message received: " + msg);

    // JSON parsing
    StaticJsonDocument<200> doc;
    DeserializationError error = deserializeJson(doc, msg);
    if (!error) {
        // Process JSON data
        int action = doc["action"];
        // Call appropriate function based on action
    }
}

void reconnect() {
    // Loop until we're reconnected
    while (!client.connected()) {
        Serial.print("Attempting MQTT connection...");
        if (client.connect("ESP8266Client")) {
            Serial.println("connected");
            client.subscribe("motion/lights/control");
        } else {
            Serial.print("failed, rc=");
            Serial.print(client.state());
            delay(2000);
        }
    }
}

void setup() {
    Serial.begin(115200);
    setupWiFi();
    client.setServer(mqtt_server, 1883);
    client.setCallback(callback);
}

void loop() {
    if (!client.connected()) {
        reconnect();
    }
    client.loop();
    // Main control logic for motion light
}

