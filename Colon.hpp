//Ryan Peterson
#include <iostream>
#include <cstdlib>
#include <string>

#ifndef COLON_H
#define COLON_H

using namespace std;

class Colon : public ClockCharacter
{
private:
    //private variables and static constants
    static const int ROWS = 10;
    static const int COLUMNS = 1;
    //establish array for colon
    string digitArray [ROWS+1][COLUMNS+1];

public:
    //constructor
    colon ()
    {
        //initialize the array when constructed
        initialize();
    }//end constructor
    //function to set colon
    void setColon()
    {
        clearColon();
        int col = 1;
        //loop function for drawing colon
        for (int i = 2; i <= 3; i ++)
        {
            digitArray [i][col] = "*";
        }//end first loop
        for (int j = 7; j<=8; j++)
        {
            digitArray [j][col] = "*";
        }//end second loop

    }//end function
    //clear function
    void clearColon()
    {
        //for loop to step through the array
        for (int i = 0; i <= ROWS; i++)
        {
            for (int j = 0; j <= COLUMNS; j++)
            {
                //fill array with nothing " "
                digitArray [i][j] = " ";
            }//end loop
        }//end loop
    }//end function
    //virtual function to display rows of array
    virtual string getRow (int aRow)
    {
        string FullRow = "";
        //step through for each row displaying column content
        for (int i = 0; i <= COLUMNS; i++)
        {
            //return for function when called from created object
            FullRow += digitArray[aRow][i];
        }//end for loop
    return FullRow;
    }//end function
    //function to initialize array
    void initialize ()
    {
        //step though to fill array and initialize
        for (int i = 0; i <= ROWS; i++)
        {
            for (int j = 0; j <= COLUMNS; j++)
            {
                //initialize with nothing in the string " "
                digitArray [i][j] = " ";
            }//end for loop
        }//end for loop
    }//end function

};//end class

#endif // COLON_H
