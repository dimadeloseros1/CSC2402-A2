#include <iomanip>
#include <iostream>

using namespace std;

class FirstQuestion {
public:
    void generalInfo() {
        cout << "This program assigns seats for a commercial airplane." << endl;
        cout << "The current seat assignments are as follows." << endl << endl;
    }

    void generalGidInfo() {
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

    void passengerClassInfo() {
        cout << "* -- available seat" << endl;
        cout << "X -- available seat" << endl << endl;

        cout << "Row 1 and 2 are for first class passengers." << endl;
        cout << "Row 3 and 7 are for business class passengers." << endl;
        cout << "Row 8 and 13 are for economy class passengers." << endl;
    }

    static char userReserveSeat(const string &input) {
        char userInput;
        while (true) {
            try {
                cout << input << endl;
                cin >> userInput;

                userInput = tolower(userInput);
                if (userInput == 'y') {
                    break;
                } else if (userInput == 'n') {
                    break;
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

                if (userInput == 'f' || userInput == 'b' || userInput == 'e') {
                    return userInput;
                }
                throw runtime_error("Please input either f, b, or e");
            } catch (const exception &e) {
                cout << e.what() << endl;
            }
        }
    }
};


int main() {
    FirstQuestion question;
    question.generalInfo();
    question.generalGidInfo();
    question.passengerClassInfo();
    char userChoice = FirstQuestion::userReserveSeat("To reserve a seat enter Y/y(Yes), N/n(No): ");
    char userSeatChoice = FirstQuestion::ticketType(
        "Enter ticket type: F/f (first class); (B/b) (business class); E/e (economy class): ");
    return 0;
}
