//Ryan Peterson
#include <iostream>
#include <string>
using namespace std;

//global constants
const int ROWS = 10;


class ClockCharacter
{
private:
   //Field declarations

public:
   virtual string getRow(int aRow) = 0; // pure virtual function == abstract class

}; //end class

