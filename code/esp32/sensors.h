#ifndef SENSORS_H
#define SENSORS_H

#include <Arduino.h>

struct SensorData {
  int lidarLeft;
  int lidarMiddle;
  int lidarRight;
  String colorLeft;
  String colorRight;
};

void initSensors();
SensorData readAllSensors();

#endif
