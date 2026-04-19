//Main program

#include <iostream>
#include <string>
#include <iomanip>
#include "roman.h"

using namespace std;

//Top level functions prototype to be implemented
romanType add(romanType, romanType);
romanType add(romanType, int);
void printTimesTable(romanType, romanType);

int main()
{

    //test the constructors
    romanType roman1;  //default constructor
    romanType roman2 = romanType("XXIV"); //String Constructor
    romanType roman3 = romanType(33); //Integer Constructor

    //test the results from the constructors
    cout << endl << "Print the roman representation of the values" << endl;
    roman1.printRoman();
    cout << endl;
    roman2.printRoman();
    cout << endl;
    roman3.printRoman();
    cout << endl;

    //Add the rest of the tests to get the outputs as in the example output

    //Test the no parameter constructor

    //Test change the romanType value and representation

    //Check the string constructor for romanType

    //Check the value constructor for romanType

    //Check the increment and decrement operations

    //use the top level add function to add two romanTypes

    //use the overloaded add methods using an integer and a romanType as param

    //check the class method for the add function with romanType

    //check add integer class method to a romanType

    //check the times table using romanTypes
}
