#include <iostream>
using namespace std;

const int SIZE = 20;
const int ROWS = 10;
const int COLS = 4;

int inputArray(int alpha[], int size);

int main() {
    int alpha[SIZE];
    int beta[ROWS];
    int matrix[ROWS][COLS];

    inputArray(alpha, SIZE);

    return 0;
}

class SecondQuestion {

    void inputArray(int alpha[], int size) {

        cout << "Enter " << size << " integers" << endl;
        for (int i = 0; i < size; i++) {
            cout << "Enter the value: ";
            cin >> alpha[i];
        }
    }
};


