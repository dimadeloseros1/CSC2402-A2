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
    for (int i = 0; i < size; i++) {
        beta[i] = alpha[i] * 2;
        cout << beta[i];
    }
}

// Exercise "c"
void copyAlphaBeta(const int alpha[], const int beta[], int matrix[][COLS], int cols, int rows) {

    // First 5 elements of the row of matrix
    int index = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] =  alpha[index];
            index++;
        }
    }

    // Last 5 elements of the row of matrix
    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = beta[index];
            index++;
        }
    }
}
