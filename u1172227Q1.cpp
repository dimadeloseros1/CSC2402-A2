#include <iomanip>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class FirstQuestion {
public:
    bool arr[13][6] = {false};

    FirstQuestion() {
    }

    static void generalInfo() {
        cout << "This program assigns seats for a commercial airplane." << endl;
        cout << "The current seat assignments are as follows." << endl << endl;
    }

    static void generalGidInfo() {
        cout << setw(19) << "A B C  D E F" << endl;
        for (int i = 1; i <= 13; i++) {
            for (int j = 0; j < 6; j++) {
            }
            // This line adjusts the positions of the stars on the grid
            if (i <= 9) {
                cout << "Row " << setw(2) << i << " * * *  * * *" << endl;
            } else {
                cout << "Row " << i << " * * *  * * *" << endl;
            }
        }
        cout << endl;
    }

    static void passengerClassInfo() {
        cout << "* -- available seat" << endl;
        cout << "X -- available seat" << endl << endl;

        cout << "Row 1 and 2 are for first class passengers." << endl;
        cout << "Row 3 and 7 are for business class passengers." << endl;
        cout << "Row 8 and 13 are for economy class passengers." << endl;
    }

    static bool userReserveSeat(const string &input) {
        char userInput;
        while (true) {
            try {
                cout << input << endl;
                cin >> userInput;

                userInput = tolower(userInput);
                if (userInput == 'y') {
                    return true;
                } else if (userInput == 'n') {
                    return false;
                }
                throw runtime_error("Please only enter 'y' or 'n'");
            } catch (const exception &e) {
                cout << e.what() << endl;
            }
        }
        return userInput;
    }

    static char ticketType(const string &input) {
        char userInput;

        while (true) {
            try {
                cout << input << endl;
                cin >> userInput;
                userInput = tolower(userInput);

                // This line checks if the user only inputs letters 'f', 'b', or 'e'
                if (userInput == 'f' || userInput == 'b' || userInput == 'e') {
                    return userInput;
                }
                throw runtime_error("Please input either f, b, or e");
            } catch (const exception &e) {
                cout << e.what() << endl;
            }
        }
    }

    static int rowNumber(const string &input) {
        int userInput;

        while (true) {
            try {
                cout << input << endl;
                cin >> userInput;

                // Checkin for numerical values
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    throw runtime_error("Please only enter numerical values");
                }

                // Checkin only for values within the row
                if (userInput >= 1 and userInput <= 13) {
                    // we subtract (userInput - 1) so once we assign the value to the grid, the correct seat can be shown on the grid
                    return userInput - 1;
                }
                throw runtime_error("Please only enter a number between 1 and 13");
            } catch (const exception &e) {
                cout << e.what() << endl;
            }
        }
    }

    // This function reserves the specific seat in the row
    static int seatLetter(const string &prompt) {
        char input;
        while (true) {
            cout << prompt << endl;
            cin >> input;
            input = tolower(input);

            if (input >= 'a' && input <= 'f') {
                // This line is crucial for the correct transforming char to int
                // Here we are using ASCII numbers to convert them to the proper integers starting from index 0
                return input - 'a';
            } else {
                cout << "Please only input either A, B, C, D, E, or F" << endl;
            }
        }
    }

    void GameManager(int rowNumber, int colNumber) {
        // Assigning false to the boolean array to avoid missmatched data in the grid


        cout << endl;
        cout << setw(22) << " A  B  C  D  E  F" << endl;
        for (int i = 0; i < 13; i++) {
            // Using setw function to correctly align the stars in the grid
            cout << "Row " << setw(2) << i + 1;
            arr[rowNumber][colNumber] = "X";
            for (int j = 0; j < 6; j++) {
                // This line adjusts the positions of the stars on the grid
                if (arr[i][j] == false) {
                    cout << " * ";
                } else {
                    cout << " X ";
                }
            }
            cout << endl;
        }

        cout << "* -- available seat" << endl;
        cout << "X -- occupied seat" << endl;
    }
};


int main() {
    FirstQuestion question;
    FirstQuestion::generalInfo();
    FirstQuestion::generalGidInfo();
    FirstQuestion::passengerClassInfo();
    char userChoice = FirstQuestion::userReserveSeat("To reserve a seat enter Y/y(Yes), N/n(No): ");
    while (userChoice) {
        char userSeatChoice = FirstQuestion::ticketType(
            "Enter ticket type: F/f (first class); (B/b) (business class); E/e (economy class): ");
        int userNum = FirstQuestion::rowNumber("Enter Row number 3 - 7: ");
        const auto seatNumber = FirstQuestion::seatLetter("Enter seat number (A - F): ");
        cout << seatNumber;
        question.GameManager(userNum, seatNumber);
    }
    return 0;
}
