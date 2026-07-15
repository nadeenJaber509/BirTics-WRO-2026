# Electrical Wiring

This document describes the electrical wiring used in the current BirTics robot prototype.

The objective of this document is to record how each subsystem is connected to the ESP32 during development and testing. Since the robot is still under active development, some GPIO assignments may change before the final competition version.

---

# System Overview

The electronic system is centered around an **ESP32 DevKit V1** mounted on an expansion shield.

The ESP32 communicates with:

- Three VL6180X Time-of-Flight sensors
- Two TCS3200 color sensors
- L298N H-Bridge motor driver
- Steering servo
- DC drive motor

Power is supplied by a rechargeable 9 V battery.

---

# Prototype Wiring

<p align="center">
<img src="../../assets/robot/prototype-top.jpg" width="700">
</p>

The image above shows the current prototype during the hardware integration stage.

---

# Battery Placement

<p align="center">
<img src="../../assets/robot/battery-placement.jpg" width="500">
</p>

The battery is currently positioned above the rear drive assembly.

This placement was selected to:

- keep the wiring short,
- simplify power distribution,
- allow easy battery replacement during testing.

The battery location may be adjusted after the complete sensor integration and weight balancing.

---

# ESP32 Connections

The ESP32 DevKit V1 acts as the central controller and manages all sensors and actuators.

---

# VL6180X Time-of-Flight Sensors

The three VL6180X sensors share the same I²C bus while using individual shutdown pins to avoid address conflicts.

| Signal | ESP32 Pin |
|---------|-----------|
| SDA | GPIO21 |
| SCL | GPIO22 |
| Left SHUT | GPIO25 |
| Center SHUT | GPIO26 |
| Right SHUT | GPIO27 |

---

# TCS3200 Color Sensor

The front color sensor is currently connected as follows.

| Signal | ESP32 Pin |
|---------|-----------|
| S0 | GPIO18 |
| S1 | GPIO19 |
| S2 | GPIO16 |
| S3 | GPIO17 |
| OUT | GPIO4 |
| VCC | 3.3 V |
| GND | GND |

The second color sensor will be integrated after the calibration stage.

---

# L298N Motor Driver

The motor driver is currently connected for subsystem testing.

| L298N | ESP32 |
|--------|-------|
| ENA | GPIO13 |
| IN1 | GPIO14 |
| IN2 | GPIO27 *(temporary test connection)* |
| GND | GND |

The drive motor is connected to OUT1 and OUT2.

---

# Power Distribution

The electrical power flow is currently organized as follows:

```text
9 V Battery
      │
      ▼
   Power Switch
      │
      ├────────► L298N Motor Driver
      │
      ▼
Voltage Regulator
      │
      ▼
ESP32 DevKit V1
      │
      ├── VL6180X Sensors
      ├── TCS3200 Sensors
      └── Steering Servo
```

All electronic modules share a common ground to ensure reliable communication and stable operation.

---

# Engineering Notes

During subsystem testing, a GPIO conflict was identified between:

- VL6180X Right SHUT (GPIO27)
- L298N IN2 (GPIO27)

Since the motor driver test was performed independently from the complete sensor system, the temporary overlap did not affect validation.

The final integrated firmware will use an updated GPIO allocation before the complete robot integration.

---

# Current Wiring Status

| Subsystem | Status |
|-----------|--------|
| ESP32 | ✅ Operational |
| Expansion Shield | ✅ Operational |
| Three VL6180X Sensors | ✅ Operational |
| L298N Wiring | ✅ Verified |
| Motor Rotation Test | 🟡 Independent Test Completed |
| TCS3200 Sensor | 🟡 Calibration in Progress |
| Complete Robot Wiring | 🔄 Under Integration |
