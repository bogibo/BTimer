# BTimer
Timer for arduino. 

You can set a timeout, an interval and interval for particular times tick.

## How to use

* Timeout

Example:

```arduino
#include <BTimer.h>
BTimer timer1;

void setup() {
  timer1.setTimeout(1000); // will tick once after one second
}

void loop() {
  boolean i = timer1.run(); // it will return "true" when the timer is tick.
}
```

* Interval

Example:

```arduino
#include <BTimer.h>
BTimer timer1;

void setup() {
  timer1.setInterval(1000, false); // 1000 - time for interval
                                  // false - timer is running, true - stoped
}

void loop() {
  boolean i = timer1.run(); // will tick every one second
  }
```

* Interval for n times

Example:

```arduino
#include <BTimer.h>
BTimer timer1;

void setup() {
  timer1.setCounter(1000, 10); // 1000 - time for interval
                              // 10 - how many times the timer should tick
}

void loop() {
  boolean i = timer1.run(); // will tick every one second 10 times in a row and then will be stopped
  }
```

*If you want to use it repeatedly just call it again.*
