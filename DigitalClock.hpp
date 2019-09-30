//Ryan Peterson
#include <iostream>
#include <cstdlib>
#include <string>
#include <windows.h>


#ifndef DIGITALCLOCK_H
#define DIGITALCLOCK_H

using namespace std;

class DigitalClock
{
private:
    //private variables for class
    int Hours;
    int Minutes;
    int Seconds;
    //build display object
    DigitalClockDisplay aDigitalClockDisplay = DigitalClockDisplay();

public:
    //constructor
    DigitalClock()
    {

    }//end constructor
    //set time function
    void setTime (int theHours, int theMinutes, int theSeconds)
    {
        //set times to fields
        Hours = theHours;
        Minutes = theMinutes;
        Seconds = theSeconds;

        //send times to display object
        aDigitalClockDisplay.setHours(Hours);
        aDigitalClockDisplay.setMinutes(Minutes);
        aDigitalClockDisplay.setSeconds(Seconds);
    }//end function
    //function for incrementing minutes
    void incrementHours()
    {
        //set hours to new hours
        Hours++;
        //rollover if
        if (Hours > MAX_HOURS)
        {
            Hours = MIN_HOURS;
        }//end if
        //send new hours to set time function
        setTime(Hours, Minutes, Seconds);

    }//end function
    //function for incrementing minutes
    void incrementMinutes()
    {
        //set minutes to new minutes
        Minutes++;
        if (Minutes > MAX_TIME)
        {
            Minutes = MIN_TIME;
        }//end if
        //roll under if
        //send new minutes to time function
        setTime(Hours, Minutes, Seconds);
    }//end function
    // function for incrementing seconds
    void incrementSeconds()
    {
        //set seconds to new seconds
        Seconds++;
        //if seconds are over, rollover
        if (Seconds > MAX_TIME)
        {
            Seconds = MIN_TIME;
        }//end if
        //send new seconds to time function
        setTime(Hours, Minutes, Seconds);

    }//end function
    //function for hour decrement
    void decrementHours()
    {
        //set hours to new hours
        Hours--;
        //roll under if
        if (Hours < MIN_TIME)
        {
            Hours = MAX_HOURS;
        }//end if
        //send new hours to time function
        setTime(Hours, Minutes, Seconds);

    }//end function
    //function for decrement of minutes
    void decrementMinutes()
    {
        //est minutes to new minutes
        Minutes--;
        if (Minutes < MIN_TIME)
        {
            Minutes = MAX_TIME;
        }//end elif
        //send new minutes to time function
        setTime(Hours, Minutes, Seconds);

    }//end function
    //function for decrement of seconds
    void decrementSeconds()
    {
        //set seconds to new seconds
        Seconds--;
        //roll under for seconds
        if (Seconds < MIN_TIME)
        {
            Seconds = MAX_TIME;
        }//end if
        //send new seconds to time function
        setTime(Hours,Minutes, Seconds);

    }//end function
    //time display function
    void displayTime()
    {
        //run display time from object
        aDigitalClockDisplay.displayTime();
    }
    //run clock
    void run()
    {
        //every run add seconds
        incrementSeconds();
        //if second go over 59 add minute
        if (Seconds == MIN_TIME)
        {
            incrementMinutes();

        }//end if
        // if minutes go over 59 add hour
        if (Minutes == MIN_TIME && Seconds == MIN_TIME)
        {
            incrementHours();
        }//end function
        //counter system to wait one second before running the function again
        Sleep (1000);

    }//end function
};//end public

#endif // DIGITALCLOCK_H
