#define DEBUG
#ifdef DEBUG
#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>

using namespace std;
#endif

class Solution {
public:
    string intToRoman(int);
private:
    string bitToRoman(int, string, string, string);
};

string Solution::intToRoman(int num) {
    int val1 = num % 10, val2 = num % 100 / 10, val3 = num % 1000 / 100, val4 = num % 10000 / 1000;
    string s = bitToRoman(val4, "M", "", "")
             + bitToRoman(val3, "C", "D", "M")
             + bitToRoman(val2, "X", "L", "C")
             + bitToRoman(val1, "I", "V", "X");
    return s;
}

string Solution::bitToRoman(int val, string I, string V, string X) {
    string str;
    switch (val) {
        case 0: str = ""; break;
        case 1: str = I; break;
        case 2: str = I + I; break;
        case 3: str = I + I + I; break;
        case 4: str = I + V; break;
        case 5: str = V; break;
        case 6: str = V + I; break;
        case 7: str = V + I + I; break;
        case 8: str = V + I + I + I; break;
        case 9: str = I + X; break;
    }
    return str;
}


#ifdef DEBUG
int main() {
    Solution sl;
    cout << sl.intToRoman(1) << endl;
    return 0;
}
#endif

