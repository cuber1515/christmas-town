int soundPin = A0;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
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
