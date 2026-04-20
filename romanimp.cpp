//Roman Number Implementation file

#include <iostream>
#include <string>
#include "roman.h"

using namespace std;

romanType::romanType() {
    romanNum = "I";
    num = 1;
}

romanType::romanType(int nums) {
    nums = num;
    romanNum = intToRoman(nums);
}

romanType::romanType(string str) {
    romanNum = str;
    romanToPositiveInteger();
}

/*
 *  Next I will add the "setters"
 *
 */

// This method accepts a numerical string and derives the integer value
void romanType::setRoman(int number) {
    num = number;
    romanNum = intToRoman(number);
}

void romanType::setRoman(string str) {
    romanNum = str;
    romanToPositiveInteger();
}

// Conversion helper functions
// This function is in charge of handling subtractive pairs of the roman numbers
void romanType::romanToPositiveInteger() {
    num = 0;

    auto charArr = [](char c) {
        switch (c) {
            case 'I':
                return 1;
            case 'V':
                return 5;
            case 'X':
                return 10;
            case 'L':
                return 50;
            case 'C':
                return 100;
            case 'D':
                return 500;
            case 'M':
                return 1000;
            default:
                return 0;
        }
    };

    for (int i = 0; i < romanNum.length(); i++) {
        int curentVal = charArr(romanNum[i]);
        int nextVal = 0;

        if (i + 1 < romanNum.length()) {
            nextVal = charArr(romanNum[i + 1]);
        }
        else {
            nextVal = 0;
        }


        if (curentVal < nextVal) {
            num -= curentVal;
        }
        else {
            num += curentVal;
        }
    }
}

// The following function converts integer k to the Roman numerical string
string romanType::intToRoman(int number) {
    const int vals[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const string symbols[] = {"M", "CM", "D", "CD", "C", "XC","L", "XL", "X", "IX", "V", "IV", "I"};

    const int size = 13;
    string result;

    // This loop, loops through the vals int array
    for (int i = 0; i < size; i++) {
        do {
            result += symbols[i];
            number -= vals[i];
        } while (number >= vals[i]);
    }
    return result;
}

// Method to print positive integers
void romanType::printPositiveInteger() const {
    cout << num << endl;
}

// Method that prints roman nums
void romanType::printRoman() const {
    cout << romanNum << endl;
}

// Both of the getters

string romanType::getRoman() {
    return romanNum;
}

int romanType::getValue() {
    return num;
}

