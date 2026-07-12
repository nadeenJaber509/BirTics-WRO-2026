<div align="center">

# BirTics - WRO 2026 Future Engineers

**Autonomous self-driving car project for WRO Future Engineers 2026**

BirTics is a student engineering team from **Birzeit University, Palestine** building and documenting a self-driving robot for the WRO Future Engineers category.

[![WRO](https://img.shields.io/badge/WRO-Future%20Engineers%202026-red)](https://wro-association.org/)
[![Team](https://img.shields.io/badge/team-BirTics-blue)](docs/team-roles.md)
[![Controller](https://img.shields.io/badge/controller-ESP32-green)](docs/software-architecture/esp32_software_strategy.md)
[![Docs](https://img.shields.io/badge/docs-engineering%20record-orange)](docs/)

<!--
Hero image:
Add a robot photo or CAD render to assets/, then replace the placeholder below
with a GitHub image block that points to the real image file.
-->

> **Robot image will be added after the first mechanical build.**

</div>

---

## Project Overview

BirTics is participating in the **WRO 2026 Future Engineers Self-Driving Cars** challenge. The project focuses on designing an autonomous vehicle that can navigate the WRO track, respond to red and green traffic signs, and later complete the parking task required in the obstacle challenge.

This repository is the team's engineering record. It brings together the project documentation, hardware planning, software architecture, early source code, team responsibilities, and development notes in one place.

The README is designed as a navigation hub for judges, mentors, and reviewers. Detailed explanations are kept inside the documentation folders so the main page stays clear and easy to scan.

---

## 🧭 Repository Guide

**New to the project? Start here.**

The following guide is designed to help judges and reviewers quickly navigate the repository and locate the information they are interested in.

### ⭐ Essential Documents

| If you want to... | Open... |
|-------------------|----------|
| 👥 Meet the team and understand each member's role | [Team Roles](docs/team-roles.md) |
| 📖 Follow the project's evolution and engineering decisions | [Engineering Journal](docs/engineering-journal.md) |
| ⚙️ Explore the robot's mechanical design | [Mechanical Design](docs/mechanical-design/) |
| 💻 Understand the software architecture | [Software Architecture](docs/software-architecture/) |
| 🧪 Review testing plans and validation | [Testing](docs/testing/) |
| 📂 Browse the robot source code | [code/](code/) |

---

### 📚 Supporting Documentation

| Document | Description |
|----------|-------------|
| [Team Story](docs/story-portfolio/team-story.md) | The team's background and project motivation |
| [ESP32 Software Strategy](docs/software-architecture/esp32_software_strategy.md) | Overall software implementation approach |
| [Algorithms Plan](docs/software-architecture/algorithms_plan.md) | Navigation, control, and decision-making algorithms |
| [ESP32 Firmware](code/esp32/) | Current Arduino/ESP32 firmware implementation |
| [Python Design Prototypes](code/design/) | Early algorithm prototypes and software concepts |
| [Project Assets](assets/) | Photos, diagrams, sketches, and project media |

---

## 🚗 Robot Overview

BirTics is developing a **four-wheel, car-like autonomous vehicle** designed to comply with the **WRO Future Engineers 2026** regulations while maintaining a modular architecture that can evolve throughout the project.

The current engineering direction is summarized below.

| System | Current Selection |
|---------|-------------------|
| **Platform** | Four-wheel car-like chassis |
| **Drive System** | Rear-wheel drive with a physical rear axle |
| **Steering** | Front-wheel steering using a servo linkage |
| **Main Controller** | ESP32 DevKit V1 |
| **Distance Sensing** | Time-of-Flight (ToF) sensors |
| **Traffic Sign Detection** | Color sensors |
| **Orientation** | IMU-assisted heading stabilization |
| **Computer Vision** | Planned as a possible future extension; not part of the initial implementation |

The project currently follows a **sensor-based control approach**, with the ESP32 responsible for sensing, navigation, and motion control. The selected architecture provides a practical foundation for developing and testing the robot while leaving room for future improvements as the project evolves.

➡️ More detailed hardware decisions are documented in the **Mechanical Design** and **Hardware Distribution** documents.

---

## Repository Structure

| Folder | Purpose |
| --- | --- |
| [assets/](assets/) | Visual project materials such as future photos, sketches, CAD renders, and testing media. |
| [code/](code/) | Source code and prototypes for the robot software. |
| [docs/](docs/) | Engineering documentation, team records, architecture notes, and testing pages. |

---

## Engineering Philosophy

BirTics documents the engineering process, not only the final robot. The repository is meant to show how decisions are made, how ideas change, and how the team moves from planning to testing through clear evidence.

---

## Team

| Member | Responsibility |
| --- | --- |
| Julnar Assi | Software Lead |
| Lana Sayes | Mechanical Lead |
| Nadeen Jaber | Documentation & Testing Lead |

Full responsibilities are listed in [Team Roles](docs/team-roles.md).

---

<div align="center">

**BirTics**  
Birzeit University  
Palestine  
WRO Future Engineers 2026

*Document the decision. Build the robot. Test the result.*

</div>
