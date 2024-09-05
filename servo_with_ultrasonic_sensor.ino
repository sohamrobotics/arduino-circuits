#include <Servo.h>

// Pin Definitions
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 11;

// Constants
const int detectionThreshold = 10; // Distance in cm to trigger the servo
const int servoRestPosition = 0;
const int servoActivePosition = 90;

Servo myServo;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(servoRestPosition); // Initialize servo to rest position
}

void loop() {
  if (isObjectDetected()) {
    myServo.write(servoActivePosition);
    Serial.println("Object detected! Servo activated.");
    delay(3000);
  } else {
    myServo.write(servoRestPosition);
    Serial.println("No object detected. Servo at rest.");
  }
  
  delay(100); // Small delay to prevent too rapid updates
}

bool isObjectDetected() {
  long duration, distance;
  
  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Read the echo
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate distance
  distance = (duration * 0.034) / 2;
  
  // Return true if an object is detected within the threshold
  return (distance < detectionThreshold);
}
