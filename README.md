# HuskyLens Face Detection and LED Control

## Overview

This task demonstrates how to use the HuskyLens AI camera module to detect faces and control an LED based on the detection status. When a face is detected by the HuskyLens, the LED will turn on. If no face is detected, the LED will remain off.

## Components

- **HuskyLens AI Camera Module**: A camera module with built-in AI capabilities for object detection, face recognition, etc.
- **LED**: A light-emitting diode controlled by a microcontroller.
- **Microcontroller**: (e.g., Arduino, ESP32) to interface with HuskyLens and control the LED.
- **Power Supply**: To power the components.

## Installation

1. **Hardware Setup**:
   - Connect the HuskyLens to the microcontroller using the I2C interface
   - Connect the LED to a digital output pin on the microcontroller.
   - Ensure the power supply is properly connected.

2. **Software Setup**:
   - Install the necessary libraries for the HuskyLens and LED control in your development environment.
   - Upload the code to the microcontroller.

## Code

```cpp
void loop() {
  if (huskylens.request()) {
    if (huskylens.isObjectDetected()) {
      digitalWrite(ledPin, HIGH);  // Turn on LED if face detected
    } else {
      digitalWrite(ledPin, LOW);   // Turn off LED if no face detected
    }
  }
  delay(100);  // Small delay to prevent excessive checking
}
```
