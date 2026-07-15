# Hardware Integration Tests

This document summarizes the hardware validation performed throughout the development of the BirTics autonomous vehicle.

Rather than testing the complete robot immediately, each electronic subsystem was verified independently before integration into the final robot. This incremental approach simplified debugging, reduced integration risks, and allowed engineering decisions to be based on measured observations instead of assumptions.

The following sections summarize the tests that have been completed, the problems encountered, the implemented solutions, and the remaining work.

---

# Tested Subsystems

- ESP32 programming and serial communication
- ESP32 expansion shield
- Single VL6180X Time-of-Flight sensor
- Three VL6180X Time-of-Flight sensors
- L298N H-Bridge motor driver
- TCS3200 color sensor

---

# 1. ESP32 Programming and Communication

## Objective

Verify that the ESP32 can be programmed successfully through the Arduino IDE and communicate correctly using the Serial Monitor.

## Initial Issues

During the first programming attempts several upload problems appeared.

The Arduino IDE initially selected the wrong serial port:

```text
/dev/cu.Bluetooth-Incoming-Port
```

instead of

```text
/dev/cu.usbserial-0001
```

Additional upload errors included:

```text
Failed to connect to ESP32: No serial data received
```

```text
Wrong boot mode detected
```

```text
Download mode successfully detected, but getting no sync reply
```

## Troubleshooting

Several troubleshooting steps were performed:

- Selecting the correct USB serial port.
- Entering download mode manually when required.
- Disconnecting external hardware temporarily.
- Uploading again with only the ESP32 connected.
- Reconnecting the expansion shield after confirming successful programming.

## Result

The ESP32 uploaded successfully both as a standalone controller and while connected to the expansion shield.

Example successful output:

```text
Connected to ESP32
Hash of data verified
Hard resetting via RTS pin
```

### Status

✅ Passed

---

# 2. Single VL6180X Time-of-Flight Sensor

## Objective

Verify that one VL6180X sensor can detect nearby objects and communicate correctly over the I²C bus.

## Configuration

| Signal | ESP32 Pin |
|---------|-----------|
| SDA | GPIO 21 |
| SCL | GPIO 22 |

The Adafruit VL6180X library was installed after the initial compilation error.

## Initial Problem

The Arduino IDE initially reported:

```text
Adafruit_VL6180X.h: No such file or directory
```

Installing the required library resolved the issue.

## Results

The sensor successfully measured changing distances.

Example output:

```text
Distance: 22 mm
Distance: 25 mm
Distance: 40 mm
Distance: 62 mm
Distance: 151 mm
```

Occasionally the sensor returned

```text
Reading error, status: 7
```

which occurred when no reliable reflected signal was received.

## Engineering Observation

The VL6180X performs best at short distances, making it appropriate for obstacle detection near the vehicle.

### Status

✅ Passed

---

# 3. Three VL6180X Sensor Integration

## Objective

Operate three identical VL6180X sensors on the same I²C bus.

## Engineering Challenge

Each VL6180X starts with the default I²C address:

```text
0x29
```

Connecting three sensors directly creates an address conflict.

## Implemented Solution

Each sensor was connected to an independent shutdown (SHUT) pin.

| Sensor | GPIO | Assigned Address |
|---------|------|------------------|
| Left | GPIO 25 | 0x30 |
| Center | GPIO 26 | 0x31 |
| Right | GPIO 27 | 0x32 |

Initialization sequence:

1. Disable all sensors.
2. Enable the first sensor and assign address **0x30**.
3. Enable the second sensor and assign address **0x31**.
4. Enable the third sensor and assign address **0x32**.

## Initial Output

```text
Left: 15 mm | Center: Range error 12 | Right: 16 mm
```

The center sensor initially produced invalid measurements.

## Later Output

```text
Left: 15 mm | Center: 6 mm | Right: 15 mm
Left: 12 mm | Center: 3 mm | Right: 16 mm
Left: 15 mm | Center: 3 mm | Right: 15 mm
```

All three sensors later produced valid distance readings.

## Engineering Observation

Very small measured distances indicated that nearby chassis parts or mounting components may have entered the sensors' field of view.

The test confirmed that the software address reassignment method works correctly without requiring an external I²C multiplexer.

### Status

✅ Passed

---

# 4. L298N Motor Driver

## Objective

Verify the wiring of the L298N H-Bridge before integrating it into the robot.

## Configuration

| ESP32 | L298N |
|--------|--------|
| GPIO 13 | ENA |
| GPIO 14 | IN1 |
| GPIO 27 | IN2 |
| GND | GND |

The drive motor was connected to **OUT1** and **OUT2**.

The ESP32 and L298N shared a common ground.

## Engineering Observation

During documentation, a GPIO conflict was identified.

GPIO 27 was already assigned to the shutdown pin of the third VL6180X sensor.

The final integrated firmware therefore requires an updated motor driver pin assignment.

The wiring configuration was completed successfully.

Motor motion validation will be completed after updating the final GPIO allocation.

### Status

✅ Motor rotation verified
---

# 5. TCS3200 Color Sensor

## Objective

Verify communication between the ESP32 and a TCS3200 color sensor.

## Final Configuration

| Signal | ESP32 Pin |
|---------|-----------|
| S0 | GPIO 18 |
| S1 | GPIO 19 |
| S2 | GPIO 16 |
| S3 | GPIO 17 |
| OUT | GPIO 34 |
| VCC | 3.3 V |
| GND | GND |

The sensor was configured using **2% output frequency scaling**.

## Results

After updating the wiring and configuration, the ESP32 successfully received stable RGB pulse measurements from the TCS3200 sensor.

The working configuration used:

- S0 = LOW
- S1 = HIGH
- OUT connected to GPIO34

Different coloured objects produced different pulse durations, confirming successful communication between the ESP32 and the sensor.

## Engineering Observation

The initial configuration produced unstable or zero readings.

Moving the output signal to **GPIO34** and reducing the output frequency to **2% scaling** significantly improved the stability of the measurements.

### Status

✅ Passed

---

# Overall Test Summary

| Component | Status |
|-----------|--------|
| ESP32 Upload | ✅ Passed |
| ESP32 Expansion Shield | ✅ Passed |
| Single VL6180X | ✅ Passed |
| Three VL6180X Sensors | ✅ Passed |
| L298N Wiring | 🟡 Verified |
| Motor Rotation | ⏳ Pending |
| TCS3200 Communication | ✅ Passed |
| Complete Hardware Integration | ⏳ In Progress |

---

# Test Completion Overview

| Subsystem | Communication | Functional Test | Integration Status |
|------------|---------------|-----------------|--------------------|
| ESP32 | ✅ | ✅ | ✅ |
| VL6180X Sensors | ✅ | ✅ | ✅ |
| L298N Motor Driver | ✅ | ✅ | ✅ |
| TCS3200 Color Sensor | ✅ | ✅ | ✅ |

---

# Lessons Learned

Several engineering observations were obtained during the hardware validation process.

- Each subsystem should be tested independently before complete integration.
- Successful firmware upload does not guarantee correct hardware operation.
- Multiple I²C devices with identical default addresses require address reassignment.
- GPIO allocation should be planned globally before integrating multiple subsystems.
- Mechanical mounting directly influences sensor measurements.
- Recording unsuccessful tests is valuable because they explain later engineering decisions.

---

# Future Work

The next hardware validation stage will focus on:

- Updating the final ESP32 GPIO allocation.
- Completing L298N motor motion testing.
- Performing colour calibration under different lighting conditions.
- Testing both colour sensors simultaneously.
- Integrating all sensors into the main autonomous driving software.
- Performing complete robot-level hardware integration tests.
