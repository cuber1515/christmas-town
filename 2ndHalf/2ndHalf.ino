#include <NewPing.h>

int soundPin = A0;

#define trigPin  2
#define echoPin  4
#define MAX_DISTANCE 350 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(trigPin, echoPin, MAX_DISTANCE); // NewPing setup of pins and maximum distance.
float duration, distance;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50); // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
  
  duration = sonar.ping();
  distance = (duration / 2) * 0.0343;

  if(distance <= 30 && distance >= 15)
{
  digitalWrite(12, HIGH); 
  
 // digitalWrite(13, LOW);
  // turn the BLUE LED on (HIGH is the voltage level)

}

else
{ 
  digitalWrite(12, LOW);    // turn the BLUE LED off by making the voltage LOW
                 
}

if(distance <= 15)
{
    digitalWrite(12, HIGH); //Turn the BLUE and RED LED On
    digitalWrite(13, HIGH);
    
  //Play the speaker tones
    tone1.tone (880);  // 220 Hz
    delay (100);
    tone1.tone (220);  // 220 Hz
    delay (100);
      
}

else
{ 
 
  digitalWrite(13, LOW);
  tone1.noTone ();
      // turn the LED off by making the voltage LOW
      //turn off the speaker
                 
              
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
    //code
  }
}
