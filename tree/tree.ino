#include <Servo.h>

Servo myServo;
const int touchPIN = A1;

int RandomNumber;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(touchPIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchState = digitalRead(touchPIN); // read new state
  if (touchState == HIGH){
    if (angle < 180) {
      angle = angle+20;
      myServo.write(angle);
      delay(500);
    }
    else {
      angle = 0;
      myServo.write(angle);
      delay(2000);
    }
  }
  
}
