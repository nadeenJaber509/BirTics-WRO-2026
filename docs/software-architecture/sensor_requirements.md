# Sensor Requirements

This document describes the sensors used by the BirTics WRO Future Engineers 2026 robot and their role in the autonomous driving software.

---

# 1. VL6180X Time-of-Flight (ToF) Sensors

Quantity: **3**

Purpose:
- Detect obstacles around the vehicle
- Measure the distance to nearby objects
- Support obstacle avoidance decisions
- Provide real-time distance measurements during navigation

Priority:
**Critical**

---

# 2. TCS3200 Color Sensors

Quantity: **2**

Purpose:
- Detect the lane boundaries
- Identify the track surface beneath the robot
- Provide lane position information for steering correction

Priority:
**Critical**

---

# Sensor Data Usage

The software continuously reads data from all sensors during every control cycle.

The collected sensor data is used to:

- Detect lane boundaries
- Detect obstacles
- Estimate the robot's position within the lane
- Generate steering corrections
- Support autonomous navigation and decision making

---

# Software Requirements

The software must:

- Read all sensors continuously during operation.
- Filter invalid or noisy sensor readings when necessary.
- Process sensor data with minimal latency.
- Continue operating in real time throughout the entire run.
