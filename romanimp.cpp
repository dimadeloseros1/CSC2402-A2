
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
}

romanType::romanType(string str) {
    romanNum = str;
    romanToPositiveInteger();
}


