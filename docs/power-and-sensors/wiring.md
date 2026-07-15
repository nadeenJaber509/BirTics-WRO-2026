# Electrical Wiring

This document summarizes the electrical connections used in the current robot prototype.

---

# Main Controller

ESP32 DevKit V1

---

# VL6180X Time-of-Flight Sensors

| Sensor | ESP32 Pin |
|---------|-----------|
| SDA | GPIO21 |
| SCL | GPIO22 |
| Left SHUT | GPIO25 |
| Center SHUT | GPIO26 |
| Right SHUT | GPIO27 |

---

# TCS3200 Color Sensor

| Signal | ESP32 Pin |
|---------|-----------|
| S0 | GPIO18 |
| S1 | GPIO19 |
| S2 | GPIO16 |
| S3 | GPIO17 |
| OUT | GPIO4 |
| VCC | 3.3V |
| GND | GND |

---

# L298N Motor Driver

| L298N | ESP32 |
|--------|-------|
| ENA | GPIO13 |
| IN1 | GPIO14 |
| IN2 | GPIO27 *(temporary test connection)* |
| GND | GND |

---

# Engineering Note

During subsystem testing a GPIO conflict was identified between the third VL6180X shutdown pin and the L298N IN2 connection.

The final integrated firmware will use an updated GPIO allocation before full robot integration.
