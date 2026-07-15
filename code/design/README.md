# Software Design

This directory contains the initial software architecture developed for the BirTics WRO 2026 robot.

During the planning phase, the software was divided into independent modules to simplify development, testing, and future maintenance.

The files in this directory represent the planned software structure and algorithm decomposition. As development progresses, these modules may be updated, merged, or replaced by the final implementation.

> **Note**
>
> The executable firmware currently running on the robot is located in:
>
> ```
> code/esp32/
> ```

---

# Planned Software Modules

| File | Purpose |
|------|---------|
| `main.py` | Main program flow and module integration. |
| `sensors.py` | Sensor abstraction layer for reading ToF and color sensors. |
| `lane_following.py` | Planned lane-following logic. |
| `obstacle_detection.py` | Obstacle detection using distance sensors. |
| `pid_controller.py` | Steering correction using PID control. |
| `state_machine.py` | High-level robot behavior and operating states. |

---

# Software Architecture Philosophy

The software is designed using a modular architecture.

Each subsystem is developed independently before being integrated into the complete autonomous robot. This approach simplifies debugging, improves code readability, and allows individual algorithms to be tested separately.

As the project progresses, the software architecture will continue to evolve based on testing results and engineering decisions.
