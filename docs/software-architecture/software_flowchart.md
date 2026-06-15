# Software Flowchart

```text
POWER ON
    |
    v
IDLE
(Waiting for Start Button)
    |
    v
START BUTTON PRESSED
    |
    v
INITIALIZE SENSORS
    |
    v
FOLLOW TRACK
    |
    +-------------------+
    |                   |
    v                   |
PILLAR DETECTED? -------+
    |
   YES
    |
    v
DETECT COLOR
    |
    +-------------------+
    |                   |
    v                   v
RED               GREEN
    |                   |
PASS RIGHT        PASS LEFT
    |                   |
    +---------+---------+
              |
              v
RETURN TO TRACK
              |
              v
COUNT CORNERS
              |
              v
3 LAPS DONE?
              |
       +------+------+
       |             |
      NO            YES
       |             |
       v             v
FOLLOW TRACK     FIND PARKING
                     |
                     v
                ALIGN VEHICLE
                     |
                     v
                PARK VEHICLE
                     |
                     v
                    STOP
```
