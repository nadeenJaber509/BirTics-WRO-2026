# ESP32 Arduino Code

This directory contains the ESP32 firmware developed for the BirTics WRO 2026 Future Engineers robot.

The software is organized into two categories:

- Main robot firmware
- Individual hardware validation sketches

## Main Firmware

| File | Description |
|------|-------------|
| `main_esp32.ino` | Main robot control program |
| `config.h` | Pin definitions and system configuration |
| `sensors.h` | Sensor function declarations |
| `sensors.cpp` | Sensor implementations |

---

## Hardware Validation Sketches

These sketches were used during development to verify each hardware subsystem independently before integrating the complete robot.

| Sketch | Purpose |
|---------|---------|
| `tof-single-test` | Test a single VL6180X Time-of-Flight sensor |
| `tof-three-sensors-test` | Test three VL6180X sensors using software address assignment |
| `motor-driver-test` | Verify the L298N motor driver and DC motor operation |
| `color-sensor-test` | Test the TCS3200 color sensor and RGB readings |

---

## Development Approach

Each subsystem was tested separately before integration into the main robot software.

This approach helped identify wiring, communication, and hardware issues early in the development process while keeping the final software easier to debug and maintain.
