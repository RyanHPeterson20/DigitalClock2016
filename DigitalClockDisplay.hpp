//Ryan Peterson
#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>

#ifndef DIGITALCLOCKDISPLAY_H
#define DIGITALCLOCKDISPLAY_H


using namespace std;
//global constants
const int MAX_HOURS = 12;
const int MIN_HOURS = 1;
const int MAX_TIME = 59;
const int MIN_TIME = 0;
const int TENS_PLACE = 10;

class DigitalClockDisplay
{
private:
        //build object for display
        SevenSegment hTensDigit = SevenSegment();
        SevenSegment hOnesDigit = SevenSegment();
        SevenSegment mTensDigit = SevenSegment();
        SevenSegment mOnesDigit = SevenSegment();
        SevenSegment sTensDigit = SevenSegment();
        SevenSegment sOnesDigit = SevenSegment();
        Colon aColon = Colon();

public:
    //constructor
    DigitalClockDisplay()
    {
        aColon.setColon();

    }//end constructor
    //set hours function
    void setHours (int theTime)
    {
        //get new hours
        theTime = getHours(theTime);

        //if hours are over ten
        if (theTime >= TENS_PLACE)
        {
            //set ten and one spot for seconds
            int tens = theTime/TENS_PLACE;
            hTensDigit.setDigit(tens);
            int ones = theTime % TENS_PLACE;
            hOnesDigit.setDigit(ones);
        }//end if
        else
        {
            //if under ten
            hTensDigit.setDigit(0);
            int ones = theTime;
            hOnesDigit.setDigit(ones);
        }

    }//end function
    //function for roll over and getting proper hour
    int getHours(int hours)
    {
        //rollover if
        if (hours > MAX_HOURS)
        {
            hours = MIN_HOURS;
        }//end if
        //roll under if
        if (hours == MIN_TIME)
        {
            hours = MAX_HOURS;
        }//end if
        //return new hours
        return hours;
    }//end function

    //function for set hours
    void setMinutes (int theTime)
    {
        //get new time
        theTime = getSeconds(theTime);

        //if seconds is over ten
        if (theTime >= TENS_PLACE)
        {
            //set ten and one spot for seconds
            int tens = theTime/TENS_PLACE;
            mTensDigit.setDigit(tens);
            int ones = theTime % TENS_PLACE;
            mOnesDigit.setDigit(ones);
        }//end if
        else
        {
            //if under ten
            mTensDigit.setDigit(0);
            int ones = theTime;
            mOnesDigit.setDigit(ones);
        }//end elif


    }//end function
    //function for roll over
    int getMinutes (int Minutes)
    {
        //rollover if
        if (Minutes > MAX_TIME)
        {
            Minutes = MIN_TIME;
        }//end if
        //roll under if
        if (Minutes < MIN_TIME)
        {
            Minutes = MAX_TIME;
        }//end elif
        //return new minutes
        return Minutes;

    }//end function

    //function to set seconds
    void setSeconds(int theTime)
    {
        //get new time
        theTime = getSeconds(theTime);

        //if seconds is over ten
        if (theTime >= TENS_PLACE)
        {
            //set ten and one spot for seconds
            int tens = theTime/TENS_PLACE;
            sTensDigit.setDigit(tens);
            int ones = theTime % TENS_PLACE;
            sOnesDigit.setDigit(ones);
        }//end if
        else
        {
            //if under ten
            sTensDigit.setDigit(0);
            int ones = theTime;
            sOnesDigit.setDigit(ones);
        }//end elif

    }//end function

    //function for rollover of seconds
    int getSeconds (int Seconds)
    {
        //if seconds are over, rollover
        if (Seconds > MAX_TIME)
        {
            Seconds = MIN_TIME;
        }//end if
        //roll under for seconds
        if (Seconds < MIN_TIME)
        {
            Seconds = MAX_TIME;
        }//end if
        //return new seconds
        return Seconds;

    }//end function
    //display function
    void displayTime ()
    {
        //step though on all for each row of arrays since array row are consistent whether colon or number
        //each row prints entire contents then drops down a line to repeat
        for(int i=0; i <= ROWS; i++)
        {
            cout << hTensDigit.getRow(i);

            cout << hOnesDigit.getRow(i);

            cout << aColon.getRow(i);

            cout << mTensDigit.getRow(i);

            cout << mOnesDigit.getRow(i);

            cout << aColon.getRow(i);

            cout << sTensDigit.getRow(i);

            cout << sOnesDigit.getRow(i) << endl;
        }//end for loop

    }//end function
    //initialize function
    void initialize ()
    {

    }//end function

};//end class

#endif // DIGITALCLOCKDISPLAY_H
