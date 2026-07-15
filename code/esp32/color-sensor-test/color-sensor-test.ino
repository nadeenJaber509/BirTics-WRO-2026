/*
 * BirTics WRO 2026
 * Single TCS3200 Color Sensor Test
 *
 * S0  = GPIO 18
 * S1  = GPIO 19
 * S2  = GPIO 16
 * S3  = GPIO 17
 * OUT = GPIO 34
 *
 * The sensor output is a frequency signal.
 * pulseIn() measures the LOW pulse duration.
 *
 * Frequency scaling:
 * S0 = LOW
 * S1 = HIGH
 * This configures 2% output-frequency scaling.
 */

#define S0 18
#define S1 19
#define S2 16
#define S3 17
#define SENSOR_OUT 34

unsigned long readColorPulse(bool s2State, bool s3State) {
  digitalWrite(S2, s2State);
  digitalWrite(S3, s3State);

  delay(80);

  return pulseIn(SENSOR_OUT, LOW, 200000);
}

void setup() {
  Serial.begin(115200);
  delay(1000);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(SENSOR_OUT, INPUT);

  // 2% frequency scaling for easier measurement
  digitalWrite(S0, LOW);
  digitalWrite(S1, HIGH);

  Serial.println("TCS3200 test started");
}

void loop() {
  unsigned long red = readColorPulse(LOW, LOW);
  unsigned long blue = readColorPulse(LOW, HIGH);
  unsigned long green = readColorPulse(HIGH, HIGH);

  Serial.print("R: ");
  Serial.print(red);

  Serial.print(" | G: ");
  Serial.print(green);

  Serial.print(" | B: ");
  Serial.println(blue);

  delay(500);
}
