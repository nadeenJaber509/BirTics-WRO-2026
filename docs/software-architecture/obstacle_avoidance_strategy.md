# Obstacle Avoidance Strategy

## Purpose

The obstacle avoidance strategy enables the BirTics WRO Future Engineers 2026 robot to detect obstacles and navigate around them while maintaining safe and stable autonomous operation.

The robot continuously monitors the area in front of the vehicle and adjusts its trajectory whenever an obstacle is detected.

---

# Obstacle Detection

Obstacle detection is performed using three VL6180X Time-of-Flight (ToF) distance sensors.

The sensors continuously measure the distance between the robot and nearby objects, providing real-time information about the surrounding environment.

The software compares these distance measurements with predefined thresholds to determine whether an avoidance maneuver is required.

---

# Avoidance Strategy

When an obstacle is detected, the software performs the following sequence:

1. Confirm the obstacle using the ToF sensor readings.
2. Reduce vehicle speed if necessary.
3. Calculate a safe steering correction.
4. Drive around the obstacle.
5. Return smoothly to the driving lane.
6. Resume normal lane following.

---

# Safety Considerations

During obstacle avoidance, the software aims to:

- Maintain a safe distance from the obstacle.
- Prevent sudden steering movements.
- Keep the vehicle stable throughout the maneuver.
- Return smoothly to the original driving path.

---

# State Machine Integration

Obstacle avoidance is integrated with the robot state machine.

```text
WAIT_FOR_START
        ↓
LANE_FOLLOWING
        ↓
OBSTACLE_DETECTED
        ↓
OBSTACLE_AVOIDANCE
        ↓
LANE_FOLLOWING
```

---

# Testing

The obstacle avoidance algorithm is evaluated under different conditions, including:

- Different obstacle positions.
- Various approach distances.
- Multiple driving speeds.

The collected test results are used to improve the reliability and consistency of the avoidance behavior.
