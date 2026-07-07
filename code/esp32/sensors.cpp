#include "sensors.h"
#include "config.h"
#include <Wire.h>

void selectMultiplexerChannel(uint8_t channel)
{
  if (channel > 7) return;

  Wire.beginTransmission(0x70); // common TCA9548A address
  Wire.write(1 << channel);
  Wire.endTransmission();
}

void initSensors()
{
  Wire.begin(I2C_SDA_PIN, I2C_SCL_PIN);
  Serial.println("Sensors initialized");
}

int readLidar(uint8_t channel)
{
  selectMultiplexerChannel(channel);

  // Placeholder until VL53L0X library is added
  return 999;
}

String readColor(uint8_t channel)
{
  selectMultiplexerChannel(channel);

  // Placeholder until TCS34725 library is added
  return "unknown";
}

SensorData readAllSensors()
{
  SensorData data;

  data.lidarLeft = readLidar(LIDAR_LEFT_CHANNEL);
  data.lidarMiddle = readLidar(LIDAR_MIDDLE_CHANNEL);
  data.lidarRight = readLidar(LIDAR_RIGHT_CHANNEL);

  data.colorLeft = readColor(COLOR_LEFT_CHANNEL);
  data.colorRight = readColor(COLOR_RIGHT_CHANNEL);

  return data;
}
