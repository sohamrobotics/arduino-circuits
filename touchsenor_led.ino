int touchsensor = 2;
int pinLed = 11;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
    pinMode(touchsensor,INPUT);
    pinMode(pinLed,OUTPUT);
}

void loop() 

{
      val=digitalRead(touchsensor);

    Serial.println(val);
    delay(100);

  // put your main code here, to run repeatedly:
if(digitalRead(touchsensor) == HIGH)
{
  digitalWrite(pinLed,HIGH);
}
else
{
digitalWrite(pinLed,LOW);
}
}
