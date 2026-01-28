#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "YOUR_BLYNK_AUTH_TOKEN";
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_WIFI_PASSWORD";

#define PIR_PIN     D5
#define RELAY_PIN   D1

#define VPIN_LIGHT  V0
#define VPIN_MODE   V2
#define VPIN_STATUS V1

bool manualMode = false;
bool lightState = false;

unsigned long lastMotionTime = 0;
unsigned long autoOffDelay = 30000;

BLYNK_WRITE(VPIN_LIGHT)
{
  if (manualMode)
  {
    int value = param.asInt();
    digitalWrite(RELAY_PIN, value ? LOW : HIGH);
    lightState = value;
    Blynk.virtualWrite(VPIN_STATUS, value ? "Light ON (Manual)" : "Light OFF (Manual)");
  }
}

BLYNK_WRITE(VPIN_MODE)
{
  manualMode = param.asInt();
  Blynk.virtualWrite(VPIN_STATUS, manualMode ? "Manual Mode" : "Automatic Mode");
}

void setup()
{
  Serial.begin(9600);
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH);
  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  Blynk.run();

  if (!manualMode)
  {
    int motion = digitalRead(PIR_PIN);

    if (motion == HIGH)
    {
      digitalWrite(RELAY_PIN, LOW);
      lightState = true;
      lastMotionTime = millis();
      Blynk.virtualWrite(VPIN_STATUS, "Motion Detected");
    }

    if (lightState && (millis() - lastMotionTime > autoOffDelay))
    {
      digitalWrite(RELAY_PIN, HIGH);
      lightState = false;
      Blynk.virtualWrite(VPIN_STATUS, "No Motion");
    }
  }
}
