int touchsensor = 2;
int val=0;

void setup() {
  // put your setup code here, to run once:
   pinMode(touchsensor,INPUT);

   Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    val=digitalRead(touchsensor);

    Serial.println(val);
    delay(100);
}
