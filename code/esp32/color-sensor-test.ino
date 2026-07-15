/*
 * BirTics WRO 2026
 * Single TCS3200 Color Sensor Test
 *
 * S0  = GPIO 18
 * S1  = GPIO 19
 * S2  = GPIO 16
 * S3  = GPIO 17
 * OUT = GPIO 4
 *
 * The sensor output is a frequency signal.
 * pulseIn() measures the pulse duration.
 *
 * Smaller values usually mean stronger reflected light.
 */

#define S0 18
#define S1 19
#define S2 16
#define S3 17
#define SENSOR_OUT 4

unsigned long readColorFilter(
  bool s2State,
  bool s3State
) {
  digitalWrite(S2, s2State);
  digitalWrite(S3, s3State);

  delay(50);

  // Return 0 if no pulse is received within 100 ms.
  return pulseIn(SENSOR_OUT, LOW, 100000);
}

unsigned long readRed() {
  return readColorFilter(LOW, LOW);
}

unsigned long readBlue() {
  return readColorFilter(LOW, HIGH);
}

unsigned long readGreen() {
  return readColorFilter(HIGH, HIGH);
}

void setup() {
  Serial.begin(115200);

  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);

  pinMode(SENSOR_OUT, INPUT);

  // Configure the TCS3200 for 20% frequency scaling.
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);

  Serial.println("TCS3200 color sensor test started.");
}

void loop() {
  unsigned long red = readRed();
  unsigned long green = readGreen();
  unsigned long blue = readBlue();

  Serial.print("R: ");
  Serial.print(red);

  Serial.print("  G: ");
  Serial.print(green);

  Serial.print("  B: ");
  Serial.println(blue);

  delay(500);
}
