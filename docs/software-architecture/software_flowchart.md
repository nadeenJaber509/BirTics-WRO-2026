# Software Flowchart

```text
                POWER ON
                    |
                    v
         INITIALIZE HARDWARE
                    |
                    v
          INITIALIZE SENSORS
                    |
                    v
         WAIT FOR START BUTTON
                    |
                    v
        START BUTTON PRESSED
                    |
                    v
          ENTER MAIN CONTROL LOOP
                    |
                    v
          READ ALL SENSOR DATA
      (ToF + Color Sensors)
                    |
                    v
      CALCULATE LANE POSITION
                    |
                    v
       OBSTACLE DETECTED?
             /          \
           YES           NO
            |             |
            v             |
     EXECUTE OBSTACLE      |
        AVOIDANCE          |
            |             |
            +------->------+
                    |
                    v
      CALCULATE PID CORRECTION
                    |
                    v
      UPDATE STEERING SERVO
                    |
                    v
      UPDATE MOTOR CONTROL
                    |
                    v
      MISSION COMPLETED?
             /        \
           NO         YES
           |           |
           +-----------+
                       |
                       v
                STOP VEHICLE
```
