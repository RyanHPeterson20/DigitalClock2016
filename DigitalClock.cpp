//Ryan Peterson
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>

#include "ClockCharacter.hpp"
#include "SevenSegment.hpp"
#include "Colon.hpp"

#include "DigitalClockDisplay.hpp"
#include "DigitalClock.hpp"

using namespace std;


int main()
{
    //build boject from seven segment class
   SevenSegment aDigit = SevenSegment();

   //for loop to stpe through and print numbers
   for (int i = 0; i <= 9; i++)
   {
      aDigit.setDigit(i);
      for (int j = 0; j <= ROWS; j++)
      {
        cout << aDigit.getRow(j) << endl;
      } // end for
      cout << endl;  // output a blank row
    } // end for

   // stop to give the user a chance to examine the characters
   cout << "Scroll up to ensure the digits are well formed. Then,..." << endl;
   system("Pause");
    //build object for digital clock
   DigitalClock aDigitalClock = DigitalClock();

   // for the purpose of testing
   const int HOUR = 12;
   const int MINUTES = 57;
   const int SECONDS = 56;
   aDigitalClock.setTime(HOUR, MINUTES, SECONDS);
   system("cls"); // clear the screen to display to set the clock position
   aDigitalClock.displayTime();

string increment = "";
    //infinite while loop
   while (true)
   {
       //user input
     cout << "h,m,s to increment, H,M,S decrement, r to run";
     increment = getch();
     if (increment == "h")
     {
       aDigitalClock.incrementHours();
       system("cls");
       aDigitalClock.displayTime();
     } else //end elif
     if (increment == "m")
     {
       aDigitalClock.incrementMinutes();
       system("cls");
       aDigitalClock.displayTime();
     } else // end elif
     if (increment == "s")
     {
       aDigitalClock.incrementSeconds();
       system("cls");
       aDigitalClock.displayTime();
     } else //end elif
     if (increment == "H")
     {
       aDigitalClock.decrementHours();
       system("cls");
       aDigitalClock.displayTime();
     } else //end elif
     if (increment == "M")
     {
       aDigitalClock.decrementMinutes();
       system("cls");
       aDigitalClock.displayTime();
     } else //end elif
     if (increment == "S")
     {
       aDigitalClock.decrementSeconds();
       system("cls");
       aDigitalClock.displayTime();
     } else //end elif
     if (increment == "r")
     {
       // end the loop
       break;
     } //end if
   }//end loop

   // remove the set instructions and run the clock
   system("cls");
   aDigitalClock.displayTime();
    //infinite loop
   while (true)
   {
        //run clock through digital clock object
     aDigitalClock.run();
     system("cls");
     aDigitalClock.displayTime();
   }//end loop

   system("Pause");
   return 0;
} //End main()
