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

void printTimesTable(romanType base, romanType count) {
    cout << "\nRoman Times Table base "
            << base.getValue() << " "
            << count.getValue() << " times" << endl;

    int multiplier = base.getValue();
    int rows = count.getValue();

    for (int i = 1; i <= rows; i++) {
        romanType row(i);
        romanType product(i * multiplier);

        // Right-align each column for a neat table
        cout << setw(11) << row.getRoman() << "  *  " << base.getRoman() << "  =  " << product.getRoman() << endl;
    }
}

romanType add(romanType a, romanType b)
{
    return romanType(a.getValue() + b.getValue());
}

romanType add(romanType a, int n)
{
    return romanType(a.getValue() + n);
}

int main() {

    //test the constructors
    romanType roman1; //default constructor
    romanType roman2 = romanType("XXIV"); //String Constructor
    romanType roman3 = romanType(33); //Integer Constructor

    //test the results from the constructors
    cout << endl << "Print the romn representation of the values" << endl;
    roman1.printRoman();
    cout << endl;
    roman2.printRoman();
    cout << endl;
    roman3.printRoman();
    cout << endl;
    romanType defRType;

    cout << "Default romanType constructor with no parameter" << endl;
    cout << "Default romanType variable as Roman = ";
    cout << defRType.getRoman() << endl;
    cout << "Default romanType variable as number = ";
    cout << defRType.getValue() << endl;

    cout << "Setting the default romanType value to 44" << endl;
    defRType.setRoman(44);
    cout << "Default romanType variable as Roman = " << defRType.getRoman() << endl;
    cout << "Default romanType variable as value = " << defRType.getValue() << endl << endl;

    cout << "Get roman and value from the string constructor" << endl;
    romanType strR("XXIV");
    cout << "String constructor romanType variable as Roman = " << strR.getRoman() << endl;
    cout << "String constructor romanType variable as value = " << strR.getValue() << endl << endl;

    cout << "\nGet roman and value from the integer constructor" << endl;
    romanType intR(33);
    cout << "Number constructor romanType variable as Roman = " << intR.getRoman() << endl;
    cout << "Number constructor romanType variable as number = " << intR.getValue() << endl;

    cout << "Increment and Decrement on romanTypes" << endl;
    cout << "Increment class mthod on romanType before " << intR.getRoman();
    intR.inc();
    cout << " After call to class method inc " << intR.getRoman() << endl;

    cout << "Decrement class method on a romanType before " << intR.getRoman();
    intR.dec();
    cout << " After call to class method dec " << intR.getRoman() << endl << endl;

    //  Top-level add (romanType + romanType)
    cout << "\nAdd using functin method on romanTyes" << endl;
    romanType res = add(strR, intR);
    cout << "Add two romanType using top level function ";
    cout << strR.getRoman() << " plus " << intR.getRoman();
    cout << " = " << res.getRoman() << endl;

    cout << "\nAdd using overloaded function method on romanTyes and integer" << endl;
    romanType res2 = add(strR, 12);
    cout << "Add two romanType using top level function ";
    cout << strR.getRoman() << " plus 12 = " << res2.getRoman() << endl << endl;

    //  Class method add (romanType)
    romanType classAddition("XXIV");
    cout << "Using class method for addition of romanTypes ";
    cout << classAddition.getRoman() << " plus " << intR.getRoman();
    classAddition.add(intR); // XXIV + XXXIII = LVII
    cout << " Result = " << classAddition.getRoman() << endl;

    cout << "Using overloaded class method for addition of romanType and integer ";
    cout << classAddition.getRoman() << " plus 12";
    classAddition.add(12);
    cout << " Result = " << classAddition.getRoman() << endl;

    // Times Table
    romanType base(6), count(12);
    printTimesTable(base, count);
}
