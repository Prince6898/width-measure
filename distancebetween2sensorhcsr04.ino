int trigpin1 = 11;
int echopin1 = 12;
int trigpin2 = 9;
int echopin2 = 10;
float finalanswer;

void setup() {
  Serial.begin(9600);
  
  pinMode(trigpin1, OUTPUT);
  pinMode(echopin1, INPUT);
  pinMode(trigpin2, OUTPUT);
  pinMode(echopin2, INPUT);
}

float measureDistance(int trig, int echo) {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  unsigned long duration = pulseIn(echo, HIGH, 30000); // 30ms timeout

  if (duration == 0) {
    return -1; // No object detected
  }

  float distance = duration * 0.034 / 2; // Convert to cm
  return distance;
}

void loop() {
  // Read Sensor 1
  float distance1 = measureDistance(trigpin1, echopin1);
  delay(50); // Short delay to avoid interference

  // Read Sensor 2
  float distance2 = measureDistance(trigpin2, echopin2);

  // Display results
  Serial.print("Sensor 1: ");
  if (distance1 == -1) Serial.println("No object detected");
  else {
    Serial.print(distance1);
    Serial.println(" cm");
  }

  Serial.print("Sensor 2: ");
  if (distance2 == -1) Serial.println("No object detected");
  else {
    Serial.print(distance2);
    Serial.println(" cm");
  }

  Serial.println("----------------------");
  delay(500); // Wait before next reading
  finalanswer = 8- (distance1 + distance2);
  Serial.println("the width is ");
  Serial.print(finalanswer);
  delay(1000);
}
