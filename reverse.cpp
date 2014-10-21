#define DEBUG

#ifdef DEBUG
#include <iostream>
#include <climits>
#include <stdexcept>
using namespace std;

#endif

class Solution {
public:
    int reverse(int);
};

int Solution::reverse(int x) {
    typedef long long LL;
    LL y = 0;
    while (x != 0) {
       y = y * 10 + x % 10;
       x /= 10;
    }
    if (y > INT_MAX || y < INT_MIN) {
        throw runtime_error("out of range");
    } else {
        return (int)y;
    }
}

#ifdef DEBUG
int main() {
    return 0;
}
#endif

