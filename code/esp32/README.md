# ESP32 Firmware

This directory contains the Arduino source code developed for the ESP32 controller used in the BirTics WRO 2026 robot.

The implementation is organized into reusable modules and individual hardware validation programs.

---

# Contents

| Item | Description |
|------|-------------|
| `main_esp32.ino` | Main firmware entry point. |
| `config.h` | GPIO definitions and configuration constants. |
| `sensors.cpp` | Sensor implementation. |
| `sensors.h` | Sensor interface declarations. |

---

# Hardware Validation Programs

Each subsystem was tested independently before integration into the complete robot.

| Folder | Purpose |
|---------|---------|
| `tof-single-test` | Validation of one VL6180X sensor. |
| `tof-three-sensors-test` | Validation of three VL6180X sensors with dynamic I²C addressing. |
| `motor-driver-test` | L298N wiring and motor control validation. |
| `color-sensor-test` | TCS3200 communication and color sensor testing. |

---

# Development Approach

The firmware follows an incremental development strategy.

Individual hardware components are validated independently before being integrated into the main autonomous driving software. This approach simplifies debugging and improves software reliability.
