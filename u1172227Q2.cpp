#include <iostream>
using namespace std;

const int SIZE = 20;
const int ROWS = 10;
const int COLS = 4;

void inputArray(int alpha[], int size);
void doubleArray(int beta[], int alpha[], int size);

int main() {
    int alpha[SIZE];
    int beta[ROWS];
    int matrix[ROWS][COLS];

    inputArray(alpha, SIZE);
    doubleArray(beta, alpha, SIZE);

    return 0;
}

// Exercise "a"
void inputArray(int alpha[], int size) {
    cout << "Enter " << size << " integers" << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter the value: ";
        cin >> alpha[i];
    }
}

// Exercise "b"
void doubleArray(int beta[], const int alpha[], int size) {
    // int alphaCopy[] = ALP

    for (int i = 0; i < size; i++) {
        beta[i] = alpha[i] * 2;
        cout << beta[i];
    }
}
