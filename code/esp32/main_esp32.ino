/*
 * BirTics WRO 2026
 * ESP32 Main Program
 *
 * Hardware:
 * - ESP32 DevKit V1
 * - 3x VL53L0X LiDAR/ToF sensors
 * - I2C multiplexer
 * - 2x TCS34725 color sensors
 * - MPU6050 IMU
 * - L298N motor driver
 */

void setup()
{
  Serial.begin(115200);
  Serial.println("BirTics WRO 2026 ESP32 robot started");
}

void loop()
{
  Serial.println("Robot main loop running...");
  delay(500);
}
