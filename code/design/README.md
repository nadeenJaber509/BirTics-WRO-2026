# Software Design

This directory contains the software design and high-level architecture developed for the BirTics WRO Future Engineers 2026 robot.

The files in this directory describe the logical structure of the software before and during implementation. They are intended to document the software architecture, algorithms, and module interactions independently of the final ESP32 firmware.

The actual firmware running on the robot is implemented separately in the ESP32 project.

> **Note**
>
> The executable firmware is located in:
>
> ```
> code/esp32/
> ```

---

# Software Design Modules

| File | Purpose |
|------|---------|
| `main.py` | High-level software workflow and module integration. |
| `sensors.py` | Sensor abstraction and data acquisition design. |
| `lane_following.py` | Lane following algorithm design. |
| `obstacle_detection.py` | Obstacle detection and avoidance logic. |
| `pid_controller.py` | PID steering controller design. |
| `state_machine.py` | Robot operating states and state transitions. |

---

# Design Philosophy

The software follows a modular architecture in which each subsystem is designed independently before being integrated into the complete autonomous vehicle.

This approach provides several advantages:

- Clear separation of responsibilities
- Easier debugging and testing
- Improved code readability
- Simpler future maintenance
- Better documentation of the software architecture

The files in this directory serve as a reference for the overall software design and are kept synchronized with the implemented firmware whenever significant architectural changes are made.
