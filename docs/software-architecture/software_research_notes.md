# Software Research Notes

## Overview

This document summarizes the software concepts, design decisions, and engineering approaches researched during the development of the BirTics WRO Future Engineers 2026 robot.

---

# Sensor-Based Navigation

Several navigation approaches were evaluated during the planning stage.

The final software architecture uses dedicated sensors instead of a vision-based system, allowing all processing to run directly on the ESP32 while maintaining a simple and efficient design.

---

# Lane Following

Different lane following methods were investigated before selecting the final approach.

The implemented solution uses two TCS3200 color sensors to monitor the track surface and estimate the robot's position within the lane.

This approach provides fast sensor readings and low computational requirements.

---

# Obstacle Detection

Obstacle detection is based on three VL6180X Time-of-Flight (ToF) distance sensors.

The research focused on selecting reliable distance measurements that enable the robot to detect nearby obstacles and perform safe avoidance maneuvers.

---

# PID Control

A PID controller was selected to improve steering stability.

Research focused on:

- Reducing steering oscillation
- Improving lane tracking accuracy
- Achieving smooth steering corrections
- Maintaining stable vehicle motion

---

# Finite State Machine

The robot software is organized as a finite state machine (FSM).

This architecture separates the software into clearly defined operating states, making the control logic easier to understand, maintain, and debug.

---

# Software Modularity

The software is divided into independent modules for:

- Sensor acquisition
- Lane following
- Obstacle avoidance
- PID steering control
- State management
- Motor and servo control

This modular design simplifies testing and future software improvements.

---

# Continuous Improvement

The software is continuously evaluated through testing on the competition track.

Observations from each test session are used to refine the navigation algorithm, improve controller performance, and increase the overall reliability of the autonomous vehicle.
