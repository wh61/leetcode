#define Debug

#ifdef Debug
#include <iostream>
#include <cstdlib>
#include <climits>
using namespace std;
#endif

class Solution {
public:
    bool isPalindrome(int);
};
bool Solution::isPalindrome(int x) {
    if (x == INT_MAX) {
        return false;
    } else if (x == INT_MIN) {
        return false;
    }
    int x_ = x < 0 ? -x : x;
    int y = 0;
    while (x_ != 0) {
        y = y * 10 + x_ % 10;
        x_ /= 10;
    }
    return x == y;
}

#ifdef Debug
int main() {
    return 0;
}
#endif
