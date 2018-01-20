#include <BTimer.h>

BTimer timer1;

#define led 13

void setup() {
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  timer1.setCounter(1000, 10); // 1000 - time for interval
                              // 10 - how many times the timer should tick

}

void loop() {
  boolean i = timer1.run(); // Should run everytime for checking setted timer.
                            //It will return "true" when the timer is tick
  if(i){
    digitalWrite(led, !digitalRead(led));
  }
}
