# Motor Driver Validation

## Objective

Verify that the rear drive motor responds correctly to commands issued by the ESP32 through the L298N motor driver.

---

## Test Setup

- ESP32 DevKit V1
- L298N H-Bridge
- Rear DC motor
- 9 V battery

---

## Procedure

The motor driver was connected to the ESP32 and simple forward commands were executed.

The objective was to verify:

- Correct wiring
- Motor rotation
- Stable power delivery
- Driver functionality

---

## Result

The rear drive motor rotated successfully and responded correctly to the control commands.

### Demonstration Video

[▶ Motor Driver Test](../../assets/testing/motor-test.mp4)

---

## Engineering Observation

This validation confirmed that:

- the motor driver wiring is correct,
- the power distribution is functional,
- the rear drive mechanism operates as expected.

The next stage is integrating the motor control with the autonomous navigation software.
