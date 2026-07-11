# BirTics – WRO 2026 Future Engineers
## Hardware Distribution & Selection (V1)


**Architecture summary:**

| Chassis | Drive | Steering | Legal target |
|---|---|---|---|
| 3D printed car chassis | 1 DC motor → rear axle | 1 front servo linkage | No differential drive |

---

## 1. Confirmed Design Decisions

Based on the WRO 2026 Future Engineers rules, the vehicle must stay within the legal limits:

- 4 wheels, real driving axle, real steering actuator
- Max **300 x 200 mm** footprint
- Max **300 mm** height
- Max **1.5 kg** weight
- No differential wheeled base
- No left/right independent drive motors for steering
- No omni / ball / spherical wheels
- Wired communication only during rounds

*Figure 1 (see original document): Proposed top-view distribution — front steering, rear axle drive, central compute and low battery placement.*

---

## 2. Hardware Selection & Placement Matrix

| Subsystem | Selected choice | Placement on chassis | Voltage / power target | Why we chose it | Alternative / backup | Risk / check before buying | Status |
|---|---|---|---|---|---|---|---|
| **Chassis** | Custom 3D printed chassis | Full base, ~240–270 mm length, 150–180 mm width | N/A | Max control over size, sensor mounts, weight distribution, documentation | Small RC chassis | Must remain under 300×200 mm and total height under 300 mm | **SELECTED** |
| **Drive architecture** | Rear-wheel drive | Rear section | Motor voltage per selected motor, likely 6–12V | Simple, legal, car-like, easy to document | Front-wheel drive | Do not use left motor + right motor steering | **SELECTED** |
| **Driving motor** | 1 DC gear motor, preferably with encoder | Rear center, connected to rear axle | 6–12V target; confirm after motor datasheet | One motor avoids differential-drive risk, keeps control simple | 2 motors mechanically coupled to same axle | Must not independently drive left and right sides | **SELECTED CONCEPT** |
| **Rear axle** | Single metal rear axle with bearings | Rear, connecting both rear wheels | Mechanical part | Distributes motor motion mechanically to both wheels | Belt/pulley or gear transfer | Axle must be straight, low friction, strong | **SELECTED** |
| **Steering actuator** | Metal gear servo, DS3218 preferred; MG996R backup | Front center with steering linkage | 6V rail, at least 3A peak available | Real steering actuator required; strong enough for rubber wheels | MG996R for prototype | Never power servo from Raspberry Pi/Arduino 5V pin | **SELECTED** |
| **Wheels** | 4 rubber RC wheels | Two front steering, two rear driven | N/A | Grip, stability, legal; supports parking and corner control | Foam/rubber wheels if same legal type | No omni, ball caster, or spherical wheels | **SELECTED** |
| **Motor driver** | Cytron MD10C if motor current is high; TB6612FNG only for small motors | Near rear motor, short motor wires | Input follows motor battery; logic from MCU | Reliable speed control with PWM and direction control | BTS7960 for high current | Driver current rating must exceed motor stall current | **NEED MOTOR DATASHEET** |
| **Main computer** | Raspberry Pi 5 or Pi 4 | Center/top deck with airflow | 5.1V, 5A stable supply for Pi 5 | Good for camera + OpenCV processing | Jetson only if heavy AI needed | Heat, brownouts, and weight must be controlled | **SELECTED** |
| **Microcontroller** | Arduino Nano or UNO | Center deck near motor driver and servo signal wires | 5V logic; powered from regulated 5V rail | Stable real-time control of motor, servo, encoder, button | Pico / STM32 | All connections to Pi must be wired; no wireless use | **SELECTED** |
| **Camera** | Wide-angle camera | Front/top, adjustable tilt | Powered by Pi CSI or USB | Needed for lane, wall, red/green pillar detection | USB wide-angle camera | Mount angle must avoid glare and see near track | **SELECTED** |
| **Distance sensors** | 2x VL53L1X ToF sensors | Front-left and front-right | Usually 3.3V/5V; confirm board | Useful for walls, parking, obstacle confirmation | Ultrasonic sensors | ToF can be affected by angle/surface; test placement | **SELECTED** |
| **IMU** | BNO055 preferred | Near center of gravity | 3.3V/5V depending on board | Gives orientation; useful for turns and stability | MPU6050 lower cost | Needs calibration and vibration isolation | **SELECTED** |
| **Encoder** | Motor encoder or magnetic wheel encoder | On motor shaft or rear axle/wheel | 3.3V or 5V depending on model | Measures speed/distance, helps stop after laps and park | Optical encoder | Must be mounted securely and tested for noise | **SELECTED** |
| **Power: motor** | 2S LiPo battery as initial target | Low center/rear-center | 7.4V nominal, current depends on motor | Good energy density and common for small cars | NiMH pack or 3S only if motor supports it | Need safe charger and fuse/protection plan | **SELECTED TARGET** |
| **Power: Pi** | Dedicated buck regulator or power bank | Low center, separate from motor noise | 5.1V / 5A for Raspberry Pi | Prevents resets when motor/servo draw current | Official Pi supply for bench testing | Common ground required with MCU when signals shared | **SELECTED** |
| **Power: servo** | Dedicated buck regulator | Near servo/front center | 6V, 3A+ recommended | Servo peaks can reset electronics if shared badly | 5V high-current rail if servo supports it | Do not share weak Pi/Arduino supply | **SELECTED** |
| **Start system** | One power switch + one start push button | Power switch accessible; start button top side | Depends on circuit; button to MCU GPIO | Matches required start procedure and avoids illegal interactions | Integrated button on controller | Only one start button; no switches used to enter data | **SELECTED** |
| **Wiring/structure** | JST/XT connectors, screw terminals, zip ties, heat shrink | All around, fixed and strain-relieved | Wire gauge based on current | Reliability and easy maintenance | Dupont only for low-current signals | Loose wires can fail during rounds | **SELECTED** |

---

## 3. Build Order: What to Buy and Test First

| Phase | Buy / prepare | Goal | Pass condition | Do not move forward until |
|---|---|---|---|---|
| **Phase 1 – Mechanical skeleton** | 3D printed base, 4 rubber wheels, rear axle, bearings, steering linkage prototype | Check size, wheel alignment, and steering freedom | Car rolls smoothly by hand and steering moves without binding | Footprint and height are safely below WRO limits |
| **Phase 2 – Motion control** | DC gear motor, motor driver, steering servo, Arduino, 6V servo regulator, motor battery | Make the car drive forward/backward and steer left/right | Start button works; motor PWM and servo angles are controllable | No overheating, no servo jitter, no illegal differential behavior |
| **Phase 3 – Vision and sensors** | Raspberry Pi, wide camera, 2 ToF sensors, IMU, encoder | Add perception and feedback | Camera sees track; ToF readings stable; encoder counts correctly | Power rails remain stable while motor and servo run |
| **Phase 4 – Competition reliability** | Cable management, spare connectors, fuse/protection, final mounts | Make the robot robust for repeated rounds | 10+ test runs without loose wires, resets, or mechanical failures | Documentation photos, wiring diagram, and test logs are updated |

---

## 4. Final Architecture Statement (Engineering Journal)

**Selected hardware architecture:** Team BirTics will build a custom 3D printed four-wheel self-driving car using rear-wheel drive and front-wheel steering. A single DC gear motor drives one rear axle mechanically connected to both rear wheels. A metal gear servo controls the front steering linkage. This choice avoids differential drive, keeps the robot car-like, supports autonomous parking, and makes the design easier to reproduce and document.

---

## 5. Quick Legal Red Flags Before Buying

**Do NOT buy:**
- 2WD smart robot chassis
- 4WD differential robot kit
- Tank/tracked chassis
- Omni wheels
- Ball caster / spherical caster
- Left/right independent drive motor system
- Any module intended for wireless control during the round

> [!NOTE]
> **Original Engineering Document**
>
> The complete planning document used during the hardware selection phase is available here:
>
> 📄 **[Hardware Distribution & Selection V1 (DOCX)](hardware-distribution-v1.docx)**
