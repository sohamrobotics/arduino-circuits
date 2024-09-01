#include <Servo.h>
Servo Serv;

int x = A0;
int y = A1;
int x_value, y_value;
int pinServo = 3;

void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   Serv.attach(pinServo);
}

void loop() {
  // put your main code here, to run repeatedly:
    x_value = analogRead (x);
    y_value = analogRead (y);


    if (x_value>=1000){
      Serv.write(10);
      delay(20);
    }

    if (x_value<=10){
        Serv.write(170);
      delay(20);
    }

    if (y_value>=1000){
      Serv.write(60);
      delay(20);
    }

    if (y_value<=10){
        Serv.write(120);
      delay(20);
    }
}
