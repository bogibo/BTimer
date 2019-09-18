/*
   bTimer.h - Library for counting time.
   Created by bogibo. January 19, 2018.
   Released into the public domain.
 */

#include "Arduino.h"
#include "BTimer.h"

BTimer::BTimer()
{
        _tm1 = 0;
        _tm2 = 0;
        _time = 0;
        _result = false;
        _startTm = false;
        _finishTm = false;
        _resetMe = false;
        _bst = false;
        _bsi = false;
        _stop = true;

}

void BTimer::setTimeout(unsigned long time)
{
        _time = time;
        _bst = true;
        _bsi = false;
        _bsc = false;
        _startTm = false;
        _finishTm = false;
}

void BTimer::setInterval(unsigned long time, boolean stop)
{
        _time = time;
        _resetMe = false;
        _bst = false;
        _bsi = true;
        _bsc = false;
        _stop = stop;
        _startTm = false;
        _finishTm = false;
}

void BTimer::setCounter(unsigned long time, int setCount)
{
        _time = time;
        _resetMe = false;
        _bst = false;
        _bsi = false;
        _bsc = true;
        _startTm = false;
        _finishTm = false;
        _counter = 0;
        _setCount = setCount;
}

boolean BTimer::run()
{
        if(_bst)
        {
                _tm1 = millis();

                if(!_startTm && !_finishTm) {
                        _startTm = true;
                        _tm2 = _tm1 + _time;
                        _result = false;
                        return _result;
                }
                else {
                        if((_tm2 <= _tm1) && !_finishTm) {
                                _finishTm = true;
                                _result = true;
                                return _result;

                        }
                        else {
                                _result = false;
                                return _result;
                        }
                }
        }
        else if(_bsi)
        {
                if(!_stop)
                {
                        _tm1 = millis();
                        if(_resetMe) {
                                _startTm = false;
                                _finishTm = false;
                                _resetMe = false;
                        }

                        if(!_startTm && !_resetMe && !_finishTm) {
                                _startTm = true;
                                _tm2 = _tm1 + _time;
                                _result = false;
                                return _result;
                        }
                        else {
                                if((_tm2 <= _tm1) && !_resetMe && !_finishTm) {
                                        _finishTm = true;
                                        _resetMe = true;
                                        _result = true;
                                        return _result;

                                }
                                else {
                                        _result = false;
                                        return _result;
                                }
                        }
                }
        }
        else if(_bsc)
        {
                if(_counter <= (_setCount - 1))
                {
                        _tm1 = millis();
                        if(_resetMe) {
                                _startTm = false;
                                _finishTm = false;
                                _resetMe = false;
                                _counter = _counter + 1;
                        }

                        if(!_startTm && !_resetMe && !_finishTm) {
                                _startTm = true;
                                _tm2 = _tm1 + _time;
                                _result = false;
                                return _result;
                        }
                        else {
                                if((_tm2 <= _tm1) && !_resetMe && !_finishTm) {
                                        _finishTm = true;
                                        _resetMe = true;
                                        _result = true;
                                        return _result;

                                }
                                else {
                                        _result = false;
                                        return _result;
                                }
                        }
                }
        }
}
