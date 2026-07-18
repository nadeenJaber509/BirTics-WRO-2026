# PID Steering Controller

## Purpose

The PID (Proportional–Integral–Derivative) controller is used to provide smooth and stable steering during autonomous navigation.

Instead of making abrupt steering corrections, the controller continuously adjusts the steering angle to keep the robot centered within the lane while minimizing oscillations.

---

# Why We Use PID

Small sensor variations can cause unstable steering if corrections are applied directly.

The PID controller improves driving performance by considering:

- Current steering error (Proportional)
- Accumulated error over time (Integral)
- Rate of change of the error (Derivative)

This results in smoother steering and more stable vehicle motion.

---

# Input Source

The PID controller receives the steering error calculated by the lane following algorithm.

The error is determined using the readings from the two TCS3200 color sensors, which estimate the robot's position relative to the lane.

---

# Error Calculation

The lane following module calculates a steering error based on the difference between the left and right color sensor readings.

The objective is to keep this error as close to zero as possible.

---

# PID Formula

```text
steering_correction =
(Kp × error) +
(Ki × accumulated_error) +
(Kd × error_change)
```

Where:

- **Kp** controls the immediate reaction to the current error.
- **Ki** compensates for accumulated long-term error.
- **Kd** reduces rapid changes and improves steering stability.

---

# Steering Output

The computed PID correction is applied to the MG996R steering servo.

```text
steering_angle = center_angle + steering_correction
```

The steering angle is continuously updated throughout autonomous operation.

---

# PID Tuning

The controller is tuned experimentally using the following approach:

1. Tune **Kp** until the robot responds correctly.
2. Adjust **Kd** to reduce oscillation.
3. Introduce **Ki** only if long-term steering bias is observed.
4. Repeat testing under different driving conditions.

---

# Expected Challenges

Possible tuning challenges include:

- Excessive oscillation
- Slow steering response
- Sensor noise
- Overshooting during steering corrections

These issues are addressed by adjusting the PID parameters and validating the controller through repeated testing.

---

# Integration

The PID controller is used by the lane following module to generate steering commands for the MG996R servo.

It operates continuously throughout autonomous navigation and is one of the core control components of the robot software.
