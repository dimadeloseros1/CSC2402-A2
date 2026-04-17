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
        cout << "X -- occupied seat" << endl << endl;

        cout << "Row 1 and 2 are for first class passengers." << endl;
        cout << "Row 3 and 7 are for business class passengers." << endl;
        cout << "Row 8 and 13 are for economy class passengers." << endl;
    }

    static bool userReserveSeat(const string &input) {
        char userInput;
        while (true) {
            cout << input << endl;
            cin >> userInput;

            userInput = tolower(userInput);
            if (userInput == 'y') {
                return true;
            } else if (userInput == 'n') {
                return false;
            } else {
                cout << "Please only enter 'y' or 'n'" << endl;
            }
        }
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

    static string ticketRowNumberInfo(const char &rowNum) {
        string input;
        switch (rowNum) {
            case 'f':
                input = "Enter Row number 1 - 2: ";
                break;
            case 'b':
                input = "Enter Row number 3 - 7: ";
                break;
            case 'e':
                input = "Enter Row number 8 - 13: ";
                break;
        }
        return input;
    }

    static int rowNumber(const string &input, const char &ticketType) {
        int userInput;

        while (true) {
            cout << input << endl;
            cin >> userInput;

            // Checkin for numerical values
            if (cin.fail()) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Please only enter numerical values");
            }

            // Checkin only for values within the row
            // we subtract (userInput - 1) so once we assign the value to the grid, the correct seat can be shown on the grid
            if (ticketType == 'f') {
                if (userInput >= 1 && userInput <= 2) {
                    return userInput - 1;
                } else {
                    cout << "Please make sure that the rows are either 1 or 2 for the First Class" << endl;
                }
            } else if (ticketType == 'b') {
                if (userInput >= 3 && userInput <= 7) {
                    return userInput - 1;
                } else {
                    cout << "Please make sure that the rows are either 3 or 7 for the Business Class" << endl;
                }
            } else if (ticketType == 'e') {
                if (userInput >= 8 && userInput <= 13) {
                    return userInput - 1;
                } else {
                    cout << "Please make sure that the rows are either 8 or 13 for the Economy Class" << endl;
                }
            } else {
                cout << "Please make sure that the letters are either f, b, or e" << endl;
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

    bool GameManager(int rowNumber, int colNumber) {
        // Assigning false to the boolean array to avoid mismatched data in the grid
        cout << endl;
        if (arr[rowNumber][colNumber] == false) {
            cout << "This seat is reserved for you" << endl;
            cout << setw(22) << " A  B  C  D  E  F" << endl;
            arr[rowNumber][colNumber] = true;
        } else {
            return false;
        }

        for (int i = 0; i < 13; i++) {
            // Using "setw" function to correctly align the stars in the grid
            cout << "Row " << setw(2) << i + 1;
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
        return true;
    }
};


int main() {
    FirstQuestion question;
    FirstQuestion::generalInfo();
    FirstQuestion::generalGidInfo();
    FirstQuestion::passengerClassInfo();
    bool userChoice;
    do {
        userChoice = FirstQuestion::userReserveSeat("To reserve a seat enter Y/y(Yes), N/n(No): ");
        if (!userChoice) break;
        char userSeatChoice = FirstQuestion::ticketType(
            "Enter ticket type: F/f (first class); (B/b) (business class); E/e (economy class): ");
        string userInputClass = FirstQuestion::ticketRowNumberInfo(userSeatChoice);
        bool seatAvailability;
        do {
            int userNum = FirstQuestion::rowNumber(userInputClass, userSeatChoice);
            const auto seatNumber = FirstQuestion::seatLetter("Enter seat number (A - F): ");
            seatAvailability = question.GameManager(userNum, seatNumber);
            if (!seatAvailability) {
                cout << "*#*#*#*# This seat is occupied *#*#*#*#" << endl;
            }
        } while (!seatAvailability);
    } while (userChoice);
    return 0;
}
