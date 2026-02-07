# MQTT API Reference

## Overview
This document provides an overview of the MQTT API used for the Dual-Purpose Motion Light with IoT Integration.

## MQTT Topics

### 1. Device Status
- **Topic:** `home/light/status`
- **Description:** Publish the current status of the light (on/off).

### 2. Motion Detection
- **Topic:** `home/light/motion`
- **Description:** Announce when motion is detected.
- **Message Format:** `{"motion_detected": true}`

### 3. Control Light
- **Topic:** `home/light/control`
- **Description:** Send commands to control the light.
- **Message Format:** `{"command": "on"}`  or `{"command": "off"}`

## Connection Details
- **Protocol:** MQTT
- **Broker Address:** `mqtt://broker.hivemq.com`
- **Port:** 1883

## Example Usage

### Publish Light Control
```javascript
const mqtt = require('mqtt');
const client  = mqtt.connect('mqtt://broker.hivemq.com');

client.on('connect', function () {
  client.publish('home/light/control', JSON.stringify({ command: 'on' }));
});
```

### Subscribe to Motion Detection
```javascript
client.on('connect', function () {
  client.subscribe('home/light/motion', function (err) {
    if (!err) {
      console.log('Subscribed to motion topic');
    }
  });
});

client.on('message', function (topic, message) {
  // message is Buffer
  console.log(message.toString());
});
```
