#include <iomanip>
#include <iostream>

using namespace std;


void generalRowInfo();

int main() {
    generalRowInfo();
}

void generalInfo() {
    cout << "This program assigns seats for a comercial airplane";
    cout << "The current seat assignments are as follows";
}

void generalRowInfo() {
    cout << setw(19) <<  "A B C  D E F" << endl;
    for (int i = 1; i <= 13; i++) {
        for (int j = 0; j < 6; j++) {
        }
        if (i <= 9) {
            cout << "Row  " << i << " * * *  * * *" << endl;
        }
        else {
            cout << "Row " << i << " * * *  * * *" << endl;
        }
    }
}
