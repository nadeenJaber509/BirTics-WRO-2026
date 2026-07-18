# ESP32 Software Strategy

## Purpose

This document describes the software architecture implemented on the ESP32 microcontroller for the BirTics WRO Future Engineers 2026 robot.

The ESP32 serves as the central controller, responsible for reading sensor data, processing navigation decisions, and controlling the steering and drive systems in real time.

---

# Main Controller

The robot is controlled by a single ESP32 development board.

The ESP32 is responsible for:

- Initializing all hardware modules
- Reading sensor data
- Executing the autonomous driving algorithm
- Controlling the steering servo
- Controlling the drive motor
- Managing the robot operating states

---

# Hardware Inputs

The ESP32 receives data from:

- Three VL6180X Time-of-Flight (ToF) distance sensors
- Two TCS3200 color sensors
- Start button

---

# Hardware Outputs

The ESP32 controls:

- MG996R steering servo
- DC drive motor through the L298N motor driver

---

# Software Modules

The software is divided into several functional modules:

- System initialization
- Sensor acquisition
- Lane following
- Obstacle detection
- Obstacle avoidance
- Steering control
- Motor control
- State machine
- Safety monitoring

---

# Main Control Loop

During autonomous operation, the ESP32 continuously performs the following sequence:

1. Read all sensor values.
2. Process lane information.
3. Detect nearby obstacles.
4. Calculate the steering command.
5. Update the steering servo.
6. Control the drive motor.
7. Repeat until the mission is completed.

This continuous control loop allows the robot to react quickly to changes in the environment while maintaining stable autonomous navigation.
## Obstacle Strategy

The TCS34725 color sensors will be used to detect red and green pillars.

- Red pillar: pass from the right side.
- Green pillar: pass from the left side.

The robot will use a safe offset maneuver to avoid moving the pillars.

## IMU Usage

The MPU-6050 IMU will support turning stability and help detect heading changes during corners.

It may also support lap counting by detecting repeated turns.

## Lap Counting Strategy

The robot must complete three laps.

Possible lap counting methods:

- Count corners using IMU heading changes.
- Count sections using turning events.
- Combine IMU data with distance sensor patterns.

The final method will be selected after testing.

## Parking Strategy

After completing the obstacle challenge laps, the robot will search for the parking area and align itself using distance sensors.

The parking algorithm will be developed in stages:

1. Detect parking area.
2. Align parallel to the wall.
3. Move slowly into the parking area.
4. Stop inside the parking zone.

## Why Not OpenCV in the First Version

OpenCV and camera-based processing require stronger processing power, such as Raspberry Pi.

Since the selected first implementation uses ESP32 only, computer vision will remain an optional future improvement.

## Current Status

This strategy is the current software direction for the ESP32-only implementation.

The next step is to create ESP32 code modules and test each sensor separately before full integration.
