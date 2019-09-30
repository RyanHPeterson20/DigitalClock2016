//Ryan Peterson
#include <iostream>
#include <string>
#include <cstdlib>

#ifndef SEVENSEGMENT_H
#define SEVENSEGMENT_H

using namespace std;

class SevenSegment : public ClockCharacter

{
private:
    //constants for ROWS and COLUMNS OF ARRAY
    static const int ROWS = 10;
    static const int COLUMNS = 7;
    //display array
    string digitArray [ROWS+1][COLUMNS+1];
    //variable
    int Value;

public:
    //constructor
    SevenSegment()
    {
        //initialize the array when constructed
        initialize();
    }//end constructor
    //set digit function, accepts value and set array segments
    void setDigit(int aValue)
    {
        //clears array first
        clearSegment (Value);
        //sets input to private variable
        Value = getDigit(aValue);
        //switch statement
        switch (Value)
        {
        //number one has the following segments
        case 0:
            setSegment(1);
            setSegment(2);
            setSegment(3);
            setSegment(5);
            setSegment(6);
            setSegment(7);
            break;
        //number 1 has the following segments
        case 1:
            setSegment(3);
            setSegment(6);
            break;
        //number 2 has the following segments
        case 2:
            setSegment(1);
            setSegment(3);
            setSegment(4);
            setSegment(5);
            setSegment(7);
            break;
        //number 3 has the following segments
        case 3:
            setSegment(1);
            setSegment(3);
            setSegment(4);
            setSegment(6);
            setSegment(7);
            break;
        //number 4 has the following segments
        case 4:
            setSegment(2);
            setSegment(3);
            setSegment(4);
            setSegment(6);
            break;
        //number 5 has the following segments
        case 5:
            setSegment(1);
            setSegment(2);
            setSegment(4);
            setSegment(6);
            setSegment(7);
            break;
        //number 6 has the following segments
        case 6:
            setSegment(1);
            setSegment(2);
            setSegment(4);
            setSegment(5);
            setSegment(6);
            setSegment(7);
            break;
        //number 7 has the following segments
        case 7:
            setSegment(1);
            setSegment(3);
            setSegment(6);
            break;
        //number 8 has all segments
        case 8:
            // for loop for all segments
            for (int i = 1; i <= 7; i++)
            {
                setSegment(i);
            }//end for loop
            break;
        //number 9 has the following segments
        case 9:
            setSegment(1);
            setSegment(2);
            setSegment(3);
            setSegment(4);
            setSegment(6);
        break;
        }//end switch
    }//end set function
    //get function
    int getDigit(int aValue)
    {
        return aValue;
    }//end function
    //set segment function
    void setSegment (int aSegment)
    {
        //Segment 1
        if (aSegment == 1)
        {
            int row = 1;
            //for loop that draws the line
            for (int i= 2; i<=6; i++)
            {
                //assign to array
                digitArray[row][i] = "*";
            }//end for loop
        }//end if
        //segment 2
        if (aSegment == 2)
        {
            int col = 1;
            //for loop that draws line segment
            for (int i = 1; i <=4; i++)
            {
                //assign to array
                digitArray[i][col]="*";
            }//end for loop
        }//end if
        //segment 3
        if (aSegment == 3)
        {
            int col = 7;
            //for loop to draw line segment
            for (int i =1; i <=4; i++)
            {
                //assign to array
                digitArray[i][col] = "*";
            }//end for loop
        }//end if
        //segment 4
        if (aSegment == 4)
        {
            int row = 5;
            //for loop to draw line
            for (int i= 2; i <=6; i++)
            {
                //assign to array
                digitArray[row][i] = "*";
            }//end for loop
        }//end if
        //segment 5
        if (aSegment == 5)
        {
            int col = 1;
            //for loop to draw line
            for (int i=6; i <=9; i++)
            {
                //assign to array
                digitArray[i][col] = "*";
            }//end for loop
        }//end if
        //segment 6
        if (aSegment == 6)
        {
            int col = 7;
            //for loop to draw line
            for (int i=6; i<=9; i++)
            {
                //assign to array
                digitArray[i][col] = "*";
            }//end for loop
        }//end if
        //segment 7
        if (aSegment == 7)
        {
            int row = 10;
            //for loop to draw line
            for (int i = 2; i <= 6; i++)
            {
                //assign to array
                digitArray[row][i] = "*";
            }//end for loop
        }//end if

    }//end function
    //clear segment function
    void clearSegment(int aSegment)
    {
        //for loop to step through and clear array for new set of segments
        for (int i = 0; i <= ROWS; i++)
        {
            for (int j = 0; j <= COLUMNS; j++)
            {
                //clear array
                digitArray [i][j] = " ";
            }//end for loop
        }//end for loop

    }//end function
    //virtual array to display rows of array
    virtual string getRow (int aRow)
    {
        //for loop for each row
        string FullRow = "";
        for (int i = 0; i <= COLUMNS; i++)
        {
            //returns array when called
            FullRow += digitArray[aRow][i];
        }//end for loop
    return FullRow;
    }//end function
    //initialize array function
    void initialize ()
    {
        //for loop to step through array
        for (int i = 0; i <= ROWS; i++)
        {
            for (int j = 0; j <= COLUMNS ; j++)
            {
                //initialize with nothing in the the string
                digitArray[i][j] = " ";
            }//end for loop
        }//end for loop
    }//end function

};//end class

#endif // SEVENSEGMENT_H
