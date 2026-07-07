#ifndef CONFIG_H
#define CONFIG_H

// I2C pins for ESP32
#define I2C_SDA_PIN 21
#define I2C_SCL_PIN 22

// I2C Multiplexer channels
#define LIDAR_LEFT_CHANNEL   0
#define LIDAR_MIDDLE_CHANNEL 1
#define LIDAR_RIGHT_CHANNEL  2

#define COLOR_LEFT_CHANNEL   3
#define COLOR_RIGHT_CHANNEL  4

// Motor driver pins
#define MOTOR_IN1_PIN 26
#define MOTOR_IN2_PIN 27
#define MOTOR_ENA_PIN 25

// Steering servo pin
#define STEERING_SERVO_PIN 14

// Start button pin
#define START_BUTTON_PIN 33

// Basic robot settings
#define BASE_SPEED 120
#define OBSTACLE_DISTANCE_THRESHOLD 250

#endif
