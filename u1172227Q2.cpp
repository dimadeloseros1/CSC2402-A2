#include <iostream>
using namespace std;

const int _size = 20;
const int _rows = 10;
const int _cols = 4;

void inputArray(int alpha[], int size);
void doubleArray(int beta[], const int alpha[], int size);
void copyAlphaBeta(const int alpha[], const int beta[], int matrix[][_cols], int cols, int rows);
void printArray(int arr[], int size);

int main() {
    int alpha[_size];
    int beta[_rows];
    int matrix[_rows][_cols];

    inputArray(alpha, _size);
    doubleArray(beta, alpha, _size);
    copyAlphaBeta(alpha, beta, matrix, _cols, _rows);
    printArray(beta, _size);

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
    }
}

// Exercise "c"
void copyAlphaBeta(const int alpha[], const int beta[], int matrix[][_cols], int cols, int rows) {

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

// Exercise "d"
void printArray(int arr[], int vol) {
    for (int i = 0; i < vol; i++) {
        cout << arr[i];

        // This line prints X amount of values per each line until reaching 15 lines
        if ((i + 1) % 15 == 0) {
            cout << endl;
        }
    }
}


