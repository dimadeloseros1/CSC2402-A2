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
        cout << "Row 3 through 7 are for business class passengers." << endl;
        cout << "Row 8 through 13 are for economy class passengers." << endl;
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
            cout << input << endl;
            cin >> userInput;
            userInput = tolower(userInput);

            // This line checks if the user only inputs letters 'f', 'b', or 'e'
            if (userInput == 'f' || userInput == 'b' || userInput == 'e') {
                return userInput;
            } else {
                cout << "Please input either f, b, or e" << endl;
            }
        }
    }

    // This function is in charge of displaying the correct rows when the user chooses either "f", "b" or "e"
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
                cout << "Please only enter numerical values" << endl;
                continue;
            }

            // Checkin only for values within the row
            // we subtract (userInput - 1) so once we assign the value to the grid, the correct seat can be shown on the grid
            if (ticketType == 'f') {
                if (userInput >= 1 && userInput <= 2) {
                    return userInput - 1;
                } else {
                    cout << "Please make sure that the rows are 1 through 2 for the First Class" << endl;
                }
            } else if (ticketType == 'b') {
                if (userInput >= 3 && userInput <= 7) {
                    return userInput - 1;
                } else {
                    cout << "Please make sure that the rows are 3 through 7 for the Business Class" << endl;
                }
            } else if (ticketType == 'e') {
                if (userInput >= 8 && userInput <= 13) {
                    return userInput - 1;
                } else {
                    cout << "Please make sure that the rows are 8 through 13 for the Economy Class" << endl;
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
        bool isAvailable;
        if (arr[rowNumber][colNumber] == false) {
            cout << "This seat is reserved for you" << endl;
            arr[rowNumber][colNumber] = true;
            isAvailable = true;
        } else {
            isAvailable = false;
        }

        cout << "       A  B  C   D  E  F" << endl;
        for (int i = 0; i < 13; i++) {
            // Using "setw" function to correctly align the stars in the grid
            cout << "Row " << setw(2) << i + 1;
            for (int j = 0; j < 6; j++) {
                // This line is crucial to set apart 3 stars from the following 3 stars as per the exercise example
                if (j == 3) {
                    cout << setw(4);
                }
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
        return isAvailable;
    }

    // This function is the one that orchestrates the functionality of the whole application.
    static void app() {
        FirstQuestion question;
        bool userChoice;

        // First we invoke 3 functions to display the information to the user of the program
        generalInfo();
        generalGidInfo();
        passengerClassInfo();

        // The first do-while loop is in charge of reserving a seat, the program will run until the user types "no" to reserve a seat
        do {
            userChoice = userReserveSeat("To reserve a seat enter Y/y(Yes), N/n(No): ");
            if (!userChoice) break;
            char userSeatChoice = ticketType(
                "Enter ticket type: F/f (first class); (B/b) (business class); E/e (economy class): ");
            string userInputClass = ticketRowNumberInfo(userSeatChoice);
            bool seatAvailability;

            // The inner do-while loop is in charge of checking whether the user did not pick an already taken seat
            do {
                int userNum = rowNumber(userInputClass, userSeatChoice);
                const auto seatNumber = seatLetter("Enter seat number (A - F): ");
                seatAvailability = question.GameManager(userNum, seatNumber);
                if (!seatAvailability) {
                    cout << "*#*#*#*# This seat is occupied *#*#*#*#" << endl;
                    cout << "Make another selection" << endl;
                }
            } while (!seatAvailability);
        } while (userChoice);
    }
};


int main() {
    FirstQuestion::app();
    return 0;
}
