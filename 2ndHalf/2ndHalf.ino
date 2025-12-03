#include <NewPing.h>
#include <PlayTone.h>

PlayTone tone1 (TCCR1A, TCCR1B, OCR1AH, OCR1AL, TCNT1H, TCNT1L);

int soundPin = A0;
int LED1 = 2;
int LED2 = 3;
int LED3 = 4;
int LED4 = 5;

#define trigPin  2
#define echoPin  4
#define MAX_DISTANCE 350 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(trigPin, echoPin, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
float duration, distance;

void setup() {
  // put your setup code here, to run once:
  pinMode (9, OUTPUT);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  
  duration = sonar.ping();
  distance = (duration / 2) * 0.0343;


  if(distance <= 15){
    //Play the speaker tones
      tone1.tone (880);  // 220 Hz
      delay (100);
      tone1.tone (220);  // 220 Hz
      delay (100);  
  }

  else { 
    digitalWrite(13, LOW);
    tone1.noTone ();

  }
    Serial.print("Distance = ");
    Serial.print(distance); // Distance will be 0 when out of set max range.
    Serial.println(" cm");
  }

  long sum = 0;
  for(int i=0; i<100; i++) // taking 100 sample of sound
  {
    sum += analogRead(soundPin);
  }

  sum = sum/100; // average the sample of sound
  if (sum >= 100) {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }
}
