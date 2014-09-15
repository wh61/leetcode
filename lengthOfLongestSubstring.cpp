#define Debug

#ifdef Debug
#include <iostream>
#include <string>
#include <map>
using namespace std;
#endif


class Solution {
public:
    int lengthOfLongestSubstring(string);
};

int Solution::lengthOfLongestSubstring(string s) {
    size_t sz = s.size();
    if (sz == 0) {
        return 0;
    }
    map<char, int> Pos;
    int head = -1;
    int ans = 0;
    for (int tail = 0; tail < sz; ++tail) {
        if (Pos.find(s[tail]) != Pos.end()) {
            head = max(head, Pos[s[tail]]);
        }
        ans = max(ans, tail - head);
        Pos[s[tail]] = tail;
    }
    return ans;
}

#ifdef Debug
int main() {
    Solution so;
    cout << so.lengthOfLongestSubstring("abcabcbb") << endl;
    return 0;
}
#endif
