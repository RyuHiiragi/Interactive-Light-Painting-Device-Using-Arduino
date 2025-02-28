#include <Adafruit_NeoPixel.h>
#include <Wire.h>
#include <MPU6050.h>

// NeoPixel configuration
#define LED_PIN 6
#define LED_COUNT 30
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// MPU6050 setup
MPU6050 mpu;

// Push button pin
#define BUTTON_PIN 2

// Motion detection threshold
const float motionThreshold = 2.0;

void setup() {
  // Initialize NeoPixel
  strip.begin();
  strip.show(); // Turn off all LEDs initially

  // Initialize MPU6050
  Wire.begin();
  mpu.initialize();
  if (!mpu.testConnection()) {
    while (1);
  }

  // Set button pin as input
  pinMode(BUTTON_PIN, INPUT);
}

void loop() {
  // Read accelerometer data
  int16_t ax, ay, az;
  mpu.getAcceleration(&ax, &ay, &az);
  float x = ax / 16384.0;
  float y = ay / 16384.0;
  float z = az / 16384.0;

  // Calculate total acceleration
  float totalAcceleration = sqrt(x * x + y * y + z * z);

  // Check for motion
  if (totalAcceleration > motionThreshold) {
    rainbowCycle(10); // Trigger rainbow effect
  } else {
    strip.clear(); // Turn off LEDs
    strip.show();
  }

  // Check button press for mode change
  if (digitalRead(BUTTON_PIN) == HIGH) {
    colorWipe(strip.Color(255, 0, 0), 50); // Red color wipe
  }
}

// NeoPixel functions (from Adafruit NeoPixel library)
void rainbowCycle(uint8_t wait) {
  for (int j = 0; j < 256; j++) {
    for (int i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

void colorWipe(uint32_t color, int wait) {
  for (int i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
