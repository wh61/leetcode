#define Debug

#ifdef Debug
#include <iostream>
#include <map>
#include <string>
using namespace std;
#endif

class Solution {
public:
    string convert(string, int);
};

string Solution::convert(string s, int nRows) {
    if (nRows == 1) {
        return s;
    }
    int x = 0, y = 0;
    int dx = 1, dy = 0;
    size_t sz = s.size();
    map<pair<int, int>, char> mp;
    for (size_t i = 0; i < sz; ++i) {
        x += dx;
        y += dy;
        mp[make_pair(x, y)] = s[i];
        if (x == nRows) {
            dx = -1;
            dy = 1;
        } else if (x == 1) {
            dx = 1;
            dy = 0;
        }
    }
    string str;
    typedef map<pair<int, int>, char>::iterator mapIter;
    for (mapIter it = mp.begin(); it != mp.end(); ++it) {
        str.push_back(it->second);
    }
    return str;
}


#ifdef Debug
int main() {
    return 0;
}
#endif

