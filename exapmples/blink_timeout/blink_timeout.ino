#include <BTimer.h>

BTimer timer1;

#define led 13

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  timer1.setTimeout(1000); // time in millis

}

void loop() {
  boolean i = timer1.run(); // Should run everytime for checking setted timer.
                            //It will return "true" when the timer is tick
  if(i){
    digitalWrite(led, !digitalRead(led));
    timer1.setTimeout(1000); // for reset a timeout call it again
  }
}
