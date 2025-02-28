# Interactive Light Painting Device Using Arduino

This repository contains the Arduino code, configuration, and assembly instructions for building an interactive light painting device using NeoPixel LEDs and an MPU6050 accelerometer. The system creates dynamic light effects triggered by motion, enabling users to "paint" with light during long-exposure photography <button class="citation-flag" data-index="1">. This project is ideal for artists, photographers, and hobbyists.

---

## Table of Contents
1. [Overview](#overview)
2. [Components Used](#components-used)
3. [System Dimensions](#system-dimensions)
4. [Assembly Instructions](#assembly-instructions)
5. [Arduino Code Explanation](#arduino-code-explanation)
6. [Contributing](#contributing)
7. [License](#license)

---

## Overview
The interactive light painting device uses an MPU6050 accelerometer to detect motion and trigger vibrant RGB light effects via NeoPixel LEDs <button class="citation-flag" data-index="7">. Users can wave the device in the air while a camera captures long-exposure shots, creating stunning light trails. A push button allows mode changes (e.g., color wipe or rainbow effect) <button class="citation-flag" data-index="1">.

---

## Components Used
To build this light painting device, you will need:
- **Arduino Uno**
- **WS2812 NeoPixel LED Strip**
- **MPU6050 Accelerometer**
- **Tactile Push Button**
- **5V Battery Pack**
- **Jumper Wires**
- **Breadboard (Optional)**

---

## System Dimensions
For an ideal handheld device:
- **Length**: 15–20 cm
- **Width**: 5–8 cm
- **Height**: 3–5 cm

---

## Assembly Instructions
1. Connect the NeoPixel LED strip to the Arduino using a dedicated 5V battery for power <button class="citation-flag" data-index="1">.
2. Connect the MPU6050 accelerometer via I2C for motion detection.
3. Add a push button to toggle light effects.
4. Secure components in a lightweight, portable enclosure.

---

## Arduino Code Explanation
The code uses the MPU6050 to detect motion and trigger NeoPixel animations. When acceleration exceeds a threshold, a rainbow cycle effect is activated. A push button toggles a red color wipe <button class="citation-flag" data-index="1">. The `rainbowCycle()` and `colorWipe()` functions are adapted from the Adafruit NeoPixel library.

---

## Contributing
Feel free to fork this repository and contribute improvements or new features. If you have suggestions or find bugs, please open an issue.

---

## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

By following this guide, you should be able to build and test your own interactive light painting device using Arduino. Happy creating! 🎨✨
