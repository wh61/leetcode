#define DEBUG
#ifdef DEBUG
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

#endif

class Solution {
public:
    int romanToInt(string);
private:
    int parse(const string&, int& , char I, char V, char X);
};
int Solution::romanToInt(string s) {
    int pos = 0;
    int val4 = parse(s, pos, 'M', ' ', ' ');
    int val3 = parse(s, pos, 'C', 'D', 'M');
    int val2 = parse(s, pos, 'X', 'L', 'C');
    int val1 = parse(s, pos, 'I', 'V', 'X');
    int val = val4 * 1000 + val3 * 100 + val2 * 10 + val1;
    return val;
}
int Solution::parse(const string& s, int &pos, char I, char V, char X) {
    size_t sz = s.size();
    if (pos == sz) {
        return 0;
    }
    if (pos + 2 < sz && s[pos] == I && s[pos + 1] == I && s[pos + 2] == I) {
        pos += 3;
        return 3;
    }
    if (pos + 1 < sz && s[pos] == I && s[pos + 1] == I) {
        pos += 2;
        return 2;
    }
    if (pos + 1 < sz && s[pos] == I && s[pos + 1] == V) {
        pos += 2;
        return 4;
    }
    if (pos + 1 < sz && s[pos] == I && s[pos + 1] == X) {
        pos += 2;
        return 9;
    }
    if (s[pos] == I) {
        pos += 1;
        return 1;
    }
    if (pos + 3 < sz 
        && s[pos] == V && s[pos + 1] == I 
        && s[pos + 2] == I && s[pos + 3] == I) {
        pos += 4;
        return 8;
    }
    if (pos + 2 < sz && s[pos] == V && s[pos + 1] == I && s[pos + 2] == I) {
        pos += 3;
        return 7;
    }
    if (pos + 1 < sz && s[pos] == V && s[pos + 1] == I) {
        pos += 2;
        return 6;
    }
    if (pos < sz && s[pos] == V) {
        pos += 1;
        return 5;
    }
    return 0;
}

#ifdef DEBUG
int main() {
    Solution sl;
    cout << sl.romanToInt("MMMIX") << endl;
    return 0;
}
#endif
