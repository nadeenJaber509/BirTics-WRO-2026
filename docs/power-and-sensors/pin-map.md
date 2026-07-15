# ESP32 GPIO Pin Map

This document summarizes the current GPIO allocation used during hardware development.

The pin assignments reflect the current prototype and will be updated if hardware integration requires changes.

---

# I²C Bus

| Signal | GPIO |
|--------|------|
| SDA | GPIO 21 |
| SCL | GPIO 22 |

---

# VL6180X Time-of-Flight Sensors

| Sensor | GPIO | Purpose |
|---------|------|---------|
| Left SHUT | GPIO 25 | Enable and assign I²C address |
| Center SHUT | GPIO 26 | Enable and assign I²C address |
| Right SHUT | GPIO 27 | Enable and assign I²C address |

Assigned I²C addresses after initialization:

| Sensor | Address |
|---------|---------|
| Left | 0x30 |
| Center | 0x31 |
| Right | 0x32 |

---

# TCS3200 Color Sensor

| Signal | GPIO |
|---------|------|
| S0 | GPIO 18 |
| S1 | GPIO 19 |
| S2 | GPIO 16 |
| S3 | GPIO 17 |
| OUT | GPIO 34 |

---

# Steering Servo

| Signal | GPIO |
|---------|------|
| PWM | TBD |

---

# Motor Driver (L298N)

| Signal | GPIO |
|---------|------|
| ENA | GPIO 13 |
| IN1 | GPIO 14 |
| IN2 | TBD |

---

# Reserved Pins

| GPIO | Purpose |
|------|---------|
| 21 | I²C SDA |
| 22 | I²C SCL |
| 25 | Left ToF SHUT |
| 26 | Center ToF SHUT |
| 27 | Right ToF SHUT |

---

# Engineering Notes

- Three VL6180X sensors share the same I²C bus after dynamic address reassignment.
- GPIO 27 was temporarily used during early motor-driver testing but is now reserved for the right VL6180X shutdown pin.
- The final motor-driver GPIO allocation will be updated after complete hardware integration.
- Additional GPIO assignments will be documented as the remaining subsystems are integrated.
