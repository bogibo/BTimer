/*
  bTimer.h - Library for counting time.
  Copyright (C) 2018, bogibo

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see http://www.gnu.org/licenses/
*/
#ifndef BTimer_h
#define BTimer_h

#include "Arduino.h"

class BTimer
{
  public:
    BTimer();
    void setTimeout(unsigned long time);
    void setInterval(unsigned long time, boolean stop);
    void setCounter(unsigned long time, int setCount);
    boolean run();
  private:
    unsigned long _tm1;
    unsigned long _tm2;
    unsigned long _time;
    boolean _resetMe;
    boolean _result;
    boolean _startTm;
    boolean _finishTm;
    boolean _bst;
    boolean _bsi;
    boolean _bsc;
    boolean _stop;
    int _counter;
    int _setCount;
};

#endif
