# Setup and Installation Guide for Dual Purpose Motion Light with IoT Integration

## Hardware Setup
1. **Components Required:**  
   - Microcontroller (e.g., Arduino, Raspberry Pi)  
   - Motion Sensor  
   - Light Source (LED/Light Bulb)  
   - Power Supply  
   - Jumper wires  
   - Breadboard (optional)

2. **Wiring Instructions:**  
   - Connect the motion sensor to the microcontroller.  
     - VCC to 5V  
     - GND to GND  
     - OUT to a digital input pin (e.g., pin 2)
   - Connect the light source to a PWM pin of the microcontroller (if applicable).
   - Ensure power supply is connected correctly.

3. **Assembling the Components:**  
   - Place the components on a breadboard.  
   - Ensure secure connections to prevent loose contacts.


## Software Configuration
### Required Software:
- **Arduino IDE** (for Arduino users)  
- **Python** (for Raspberry Pi users)

### Installation Steps:
1. **Install Arduino IDE:**  
   - Download from [Arduino's official site](https://www.arduino.cc/en/software).  
   - Follow installation instructions.

2. **Upload Code to Microcontroller:**  
   - Open the Arduino IDE.  
   - Write or paste the code for motion detection and light activation.  
   - Select the correct board and port.  
   - Click on `Upload`.

3. **Python Setup for Raspberry Pi:**  
   - Install necessary libraries using pip: `pip install RPi.GPIO`.
   - Write the Python code to handle motion detection and control the light.

4. **Testing the Setup:**  
   - Power on the device.  
   - Verify the motion sensor detects movement and activates the light.

## Troubleshooting
- **Sensor Not Responding:**  
   - Check wiring connections.  
   - Ensure power supply is adequate.
- **Light Not Turning On:**  
   - Verify code logic.  
   - Check the light source and its connections.

## Conclusion
Follow these steps to successfully install and set up your Dual Purpose Motion Light with IoT Integration. Ensure you follow the safety protocols while handling electrical components.