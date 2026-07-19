# Testing and Validation

This directory documents the testing and validation process of the BirTics WRO 2026 Future Engineers robot.

Instead of testing the complete autonomous vehicle from the beginning, each subsystem is validated independently before being integrated into the final robot. This engineering approach allows problems to be isolated, simplifies debugging, and improves the reliability of the final system.

The documentation in this section records both successful and unsuccessful tests, together with the engineering observations and improvements resulting from each validation stage.

---

# Testing Philosophy

The BirTics development process follows an incremental integration strategy.

Each hardware and software subsystem is tested separately before becoming part of the complete autonomous vehicle.

Every test aims to answer one or more of the following questions:

- Does the component communicate correctly?
- Does the wiring operate as expected?
- Does the software produce the expected behaviour?
- Are there any electrical or mechanical limitations?
- What engineering improvements are required before integration?

This methodology reduces debugging time and allows engineering decisions to be based on experimental observations rather than assumptions.

---
# Testing Roadmap

The overall validation strategy adopted during the development of the BirTics WRO 2026 robot is summarized below.

The roadmap illustrates the progressive transition from individual hardware verification to subsystem integration, algorithm validation, and complete autonomous robot testing.

<p align="center">
  <img src="../../assets/testing/testing-plan-summary.png" width="950">
</p>

The roadmap serves as a high-level reference throughout the project and helps ensure that each subsystem is validated before being integrated into the complete autonomous robot.

# Current Test Documentation

| Document | Description |
|----------|-------------|
| **hardware-integration-tests.md** | Progressive hardware validation of the ESP32, sensors, motor driver, and communication tests. |

---

# Testing Workflow

The general testing workflow adopted throughout the project is illustrated below.

```text
Component Selection
        │
        ▼
Electrical Wiring
        │
        ▼
Basic Communication Test
        │
        ▼
Functional Validation
        │
        ▼
Problem Identification
        │
        ▼
Engineering Improvements
        │
        ▼
Subsystem Integration
        │
        ▼
Complete Robot Testing
```

---

# Current Progress

| Test | Status |
|------|--------|
| ESP32 Programming | ✅ Completed |
| Serial Communication | ✅ Completed |
| Expansion Shield | ✅ Completed |
| Single ToF Sensor | ✅ Completed |
| Three ToF Sensors | ✅ Completed |
| Motor Driver Wiring | 🟡 Completed |
| Motor Motion | ⏳ Pending |
| Color Sensor Communication | 🟡 In Progress |
| Complete Robot Integration | ⏳ Pending |

---

# Future Testing

The following validation stages will be documented as development continues.

- Motor performance evaluation
- Steering calibration
- Color sensor calibration
- Autonomous driving tests
- Obstacle avoidance validation
- Wall-following performance
- Turning accuracy
- Parking behaviour
- Reliability testing
- Competition preparation

---

# Engineering Documentation Policy

Every testing document should include:

- Objective
- Hardware configuration
- Software version
- Test procedure
- Observed results
- Engineering observations
- Problems encountered
- Implemented solutions
- Final conclusion

Maintaining complete testing records helps explain engineering decisions and provides evidence of the robot's development process.
