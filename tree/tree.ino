#include <Servo.h>
#include <NewPing.h>
#include <PlayTone.h>

PlayTone tone1 (TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L);

Servo myServo;
const int touchPIN = A1;

int RandomNumber;
int angle = 0;

void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(touchPIN, INPUT);
  pinMode (9, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int touchState = digitalRead(touchPIN); // read new state
  if (touchState == HIGH){
    //Play the speaker tones
    tone1.tone (880);  // 220 Hz
    delay (100);
    tone1.tone (220);  // 220 Hz
    delay (100);

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

  else {
    tone1.noTone();
  }
  
}
