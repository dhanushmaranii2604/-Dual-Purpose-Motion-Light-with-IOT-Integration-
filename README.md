# Dual-Purpose Motion Light with IoT Integration
A dual-purpose motion-based lighting system with IoT integration, designed using ESP8266 and a PIR sensor. The system operates in automatic mode using motion detection and manual mode through a mobile application, providing real-time control, monitoring, and energy-efficient lighting.

## Features
- Automatic motion-based lighting
- Manual ON/OFF control via mobile app
- IoT-based remote access (MQTT/HTTP)
- Auto shut-off for energy saving

## Hardware
- ESP8266 (NodeMCU, Wemos D1 Mini, etc.)
- PIR motion sensor (HC-SR501 or similar)
- Relay module or MOSFET to drive the lamp/LED strip
- Power supply appropriate for the lamp and ESP8266

## Wiring (example)
- PIR VCC -> 5V (or 3.3V depending on module)
- PIR GND -> GND
- PIR OUT -> D1 (GPIO5) or other digital input on ESP8266
- Relay VCC -> 5V
- Relay GND -> GND
- Relay IN -> D2 (GPIO4) or other digital output on ESP8266

Adjust pins in the sketch as needed.

## Software / Setup
1. Copy the example config file and fill in your Wi‑Fi and server credentials:
   - `cp config.sample config.h` (or create `config.h` from the sample contents)
2. Open the Arduino IDE or PlatformIO and load the project sketch file.
3. Install required libraries: PubSubClient (for MQTT), ESP8266WiFi, ArduinoJson (if used), etc.
4. Compile and upload to your ESP8266 board.

## Operation Modes
- Automatic mode: The PIR sensor triggers the light when motion is detected. The light turns off after the configured timeout.
- Manual mode: Use the mobile app or MQTT messages to toggle the light remotely.

## MQTT topics (example)
- Command topic: `home/<device_id>/set`
- Status topic: `home/<device_id>/status`
- Motion topic: `home/<device_id>/motion`

## Security
- Do not commit `config.h` or files that contain Wi‑Fi credentials or API keys. Use `config.sample` instead and add the real file to `.gitignore`.

## Contributing
PRs welcome. Please open issues for bugs or feature requests.

## License
This project is licensed under the MIT License - see the LICENSE file for details.