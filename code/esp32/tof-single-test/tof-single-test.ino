/*
 * BirTics WRO 2026
 * Single VL6180X Time-of-Flight Sensor Test
 *
 * ESP32 I2C pins:
 * SDA = GPIO 21
 * SCL = GPIO 22
 */

#include <Wire.h>
#include <Adafruit_VL6180X.h>

Adafruit_VL6180X tof = Adafruit_VL6180X();

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(21, 22);

  Serial.println("Starting VL6180X test...");

  if (!tof.begin()) {
    Serial.println("Sensor not found! Check wiring.");

    while (true) {
      delay(100);
    }
  }

  Serial.println("Sensor connected successfully!");
}

void loop() {
  uint8_t distance = tof.readRange();
  uint8_t status = tof.readRangeStatus();

  if (status == VL6180X_ERROR_NONE) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" mm");
  } else {
    Serial.print("Reading error, status: ");
    Serial.println(status);
  }

  delay(300);
}
