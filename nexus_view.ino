 // Set ultrasonic sensor pins as input/output
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop() {
  // Trigger ultrasonic sensor 1
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  // Measure duration for ultrasonic sensor 1
  duration1 = pulseIn(echoPin1, HIGH);

  // Calculate distance for ultrasonic sensor 1
  distance1 = duration1 * 0.034 / 2;

  // Trigger ultrasonic sensor 2
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  // Measure duration for ultrasonic sensor 2
  duration2 = pulseIn(echoPin2, HIGH);

  // Calculate distance for ultrasonic sensor 2
  distance2 = duration2 * 0.034 / 2;

  // Output distance readings to serial monitor
  Serial.print("Distance from sensor 1: ");
  Serial.print(distance1);
  Serial.println(" cm");
  Serial.print("Distance from sensor 2: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // Check for obstacles in front
  if (distance1 < 30 || distance2 < 30) {
    // Obstacle detected
    Serial.println("Obstacle detected in front!");
    // Add feedback mechanism here (e.g., sound, vibration)
  }

  // Delay before next reading
  delay(100);
}