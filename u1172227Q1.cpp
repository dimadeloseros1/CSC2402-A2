#include <iomanip>
#include <iostream>

using namespace std;

void generalInfo();
void generalRowInfo();
void passengerClassInfo();

int main() {
    generalInfo();
    generalRowInfo();
    passengerClassInfo();
}

void generalInfo() {
    cout << "This program assigns seats for a commercial airplane." << endl;
    cout << "The current seat assignments are as follows." << endl << endl;
}

void generalRowInfo() {
    cout << setw(19) << "A B C  D E F" << endl;
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 6; j++) {
        }
        if (i <= 9) {
            cout << "Row " << setw(2) << i << " * * *  * * *" << endl;
        } else {
            cout << "Row " << i << " * * *  * * *" << endl;
        }
    }
    cout << endl;
}

void passengerClassInfo() {
    cout << "* -- available seat" << endl;
    cout << "X -- available seat" << endl << endl;

    cout << "Row 1 and 2 are for first class passengers." << endl;
    cout << "Row 3 and 7 are for business class passengers." << endl;
    cout << "Row 8 and 13 are for economy class passengers." << endl;
}
