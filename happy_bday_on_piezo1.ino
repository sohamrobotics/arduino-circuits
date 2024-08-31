const int buzzerPin = 8;

// Frequencies for the notes (in Hz)
int frequencies[] = {
  262, 262, 294, 262, 349, 330,
  262, 262, 294, 262, 392, 349,
  262, 262, 523, 440, 349, 330, 294,
  466, 466, 440, 349, 392, 349
};

// Durations for each note (in milliseconds)
int durations[] = {
  200, 200, 400, 400, 400, 800,
  200, 200, 400, 400, 400, 800,
  200, 200, 400, 400, 400, 400, 400,
  200, 200, 400, 400, 400, 800
};

int noteCount = sizeof(frequencies) / sizeof(frequencies[0]);

void setup() {
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  playHappyBirthday();
  delay(2000);  // Wait 2 seconds before repeating
}

void playHappyBirthday() {
  for (int i = 0; i < noteCount; i++) {
    tone(buzzerPin, frequencies[i]);
    delay(durations[i]);
    noTone(buzzerPin);
    delay(50);  // Short pause between notes
  }
}