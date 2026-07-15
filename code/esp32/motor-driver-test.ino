/*
 * BirTics WRO 2026
 * L298N H-Bridge and Single DC Motor Test
 *
 * ENA = GPIO 13
 * IN1 = GPIO 14
 * IN2 = GPIO 27
 *
 * Motor connected to OUT1 and OUT2.
 *
 * Important:
 * GPIO 27 is also used by the third ToF sensor shutdown pin
 * in the three-sensor test. This motor code is for isolated
 * testing only. The final integrated pin map must use another pin.
 */

#define ENA 13
#define IN1 14
#define IN2 27

const int PWM_FREQUENCY = 5000;
const int PWM_RESOLUTION = 8;

void stopMotor() {
  ledcWrite(ENA, 0);

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
}

void moveForward(uint8_t speedValue) {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  ledcWrite(ENA, speedValue);
}

void moveBackward(uint8_t speedValue) {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  ledcWrite(ENA, speedValue);
}

void setup() {
  Serial.begin(115200);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  ledcAttach(ENA, PWM_FREQUENCY, PWM_RESOLUTION);

  stopMotor();

  Serial.println("Motor test started.");
}

void loop() {
  Serial.println("Forward");

  moveForward(180);
  delay(3000);

  Serial.println("Stop");

  stopMotor();
  delay(2000);

  Serial.println("Reverse");

  moveBackward(180);
  delay(3000);

  Serial.println("Stop");

  stopMotor();
  delay(3000);
}
