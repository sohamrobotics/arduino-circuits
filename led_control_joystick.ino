// Pin definitions
const int VRX_PIN = A0; // Joystick X-axis
const int VRY_PIN = A1; // Joystick Y-axis
const int SW_PIN = 2;   // Joystick switch button

const int LED_RED = 9;    // Red LED
const int LED_GREEN = 10; // Green LED
const int LED_BLUE = 11;  // Blue LED

void setup() {
  pinMode(VRX_PIN, INPUT);
  pinMode(VRY_PIN, INPUT);
  pinMode(SW_PIN, INPUT_PULLUP);
  
  pinMode(LED_RED, OUTPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_BLUE, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int xValue = analogRead(VRX_PIN);
  int yValue = analogRead(VRY_PIN);
  int buttonState = digitalRead(SW_PIN);
  
  // Map joystick values to LED brightness
  int redBrightness = map(xValue, 0, 1023, 0, 255);
  int greenBrightness = map(yValue, 0, 1023, 0, 255);
  
  // Control RED and GREEN LEDs based on joystick position
  analogWrite(LED_RED, redBrightness);
  analogWrite(LED_GREEN, greenBrightness);
  
  // Control BLUE LED based on button press
  if (buttonState == LOW) {
    digitalWrite(LED_BLUE, HIGH);
  } else {
    digitalWrite(LED_BLUE, LOW);
  }
  
  // Print values for debugging
  Serial.print("X: ");
  Serial.print(xValue);
  Serial.print(" Y: ");
  Serial.print(yValue);
  Serial.print(" Button: ");
  Serial.println(buttonState);
  
  delay(100);
}