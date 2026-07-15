/*
 * BirTics WRO 2026
 * Three VL6180X Time-of-Flight Sensors Test
 *
 * Shared I2C bus:
 * SDA = GPIO 21
 * SCL = GPIO 22
 *
 * Shutdown pins:
 * Sensor 1 = GPIO 25
 * Sensor 2 = GPIO 26
 * Sensor 3 = GPIO 27
 *
 * Assigned I2C addresses:
 * Sensor 1 = 0x30
 * Sensor 2 = 0x31
 * Sensor 3 = 0x32
 */

#include <Wire.h>
#include <Adafruit_VL6180X.h>

#define SHUT_1 25
#define SHUT_2 26
#define SHUT_3 27

#define ADDR_1 0x30
#define ADDR_2 0x31
#define ADDR_3 0x32

Adafruit_VL6180X sensor1;
Adafruit_VL6180X sensor2;
Adafruit_VL6180X sensor3;

bool startSensor(
  Adafruit_VL6180X &sensor,
  uint8_t shutPin,
  uint8_t newAddress,
  const char *name
) {
  digitalWrite(shutPin, HIGH);
  delay(20);

  // The sensor starts at the default I2C address 0x29.
  if (!sensor.begin()) {
    Serial.print("ERROR: ");
    Serial.print(name);
    Serial.println(" not detected.");

    return false;
  }

  sensor.setAddress(newAddress);
  delay(10);

  Serial.print(name);
  Serial.print(" ready at address 0x");
  Serial.println(newAddress, HEX);

  return true;
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  Wire.begin(21, 22);

  pinMode(SHUT_1, OUTPUT);
  pinMode(SHUT_2, OUTPUT);
  pinMode(SHUT_3, OUTPUT);

  // Disable all sensors before assigning new addresses.
  digitalWrite(SHUT_1, LOW);
  digitalWrite(SHUT_2, LOW);
  digitalWrite(SHUT_3, LOW);

  delay(20);

  Serial.println();
  Serial.println("=== Three VL6180X Sensors Test ===");

  if (!startSensor(sensor1, SHUT_1, ADDR_1, "Sensor 1")) {
    while (true) {
      delay(100);
    }
  }

  if (!startSensor(sensor2, SHUT_2, ADDR_2, "Sensor 2")) {
    while (true) {
      delay(100);
    }
  }

  if (!startSensor(sensor3, SHUT_3, ADDR_3, "Sensor 3")) {
    while (true) {
      delay(100);
    }
  }

  Serial.println("All sensors initialized successfully.");
}

void printDistance(
  Adafruit_VL6180X &sensor,
  const char *name
) {
  uint8_t distance = sensor.readRange();
  uint8_t status = sensor.readRangeStatus();

  Serial.print(name);
  Serial.print(": ");

  if (status == VL6180X_ERROR_NONE) {
    Serial.print(distance);
    Serial.print(" mm");
  } else {
    Serial.print("Range error ");
    Serial.print(status);
  }
}

void loop() {
  printDistance(sensor1, "Left");
  Serial.print(" | ");

  printDistance(sensor2, "Center");
  Serial.print(" | ");

  printDistance(sensor3, "Right");
  Serial.println();

  delay(300);
}
