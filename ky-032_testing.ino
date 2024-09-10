const int sensorPin = 2;  // Connect the sensor's OUT pin to Arduino's digital pin 2
const int ledPin = 13;    // We'll use the built-in LED for visual feedback

void setup() {
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("IR Obstacle Avoidance Sensor Test");
}

void loop() {
  int sensorState = digitalRead(sensorPin);
  
  if (sensorState == LOW) {
    // Obstacle detected
    digitalWrite(ledPin, HIGH);
    Serial.println("Obstacle detected!");
    delay(300);
  } else {
    // No obstacle
    digitalWrite(ledPin, LOW);
    Serial.println("No obstacle");
  }
  
  delay(100);  // Short delay to avoid flooding the serial monitor
}