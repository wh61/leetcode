#define Debug

#ifdef Debug
#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;
#endif

class Solution {
public:
    string longestPalindrome(string);
};

string Solution::longestPalindrome(string s) {
    string str("#");
    size_t s_sz = s.size();
    for (size_t i = 0; i < s_sz; ++i) {
        str.push_back(s[i]);
        str.push_back('#');
    }
    size_t sz = str.size();
    vector<int> len(sz);
    len[0] = 1;
    int mid = 0;
    for (size_t i = 1; i < sz; ++i) {
        if (i > mid + len[mid] - 1) {
            int l = i, r = i;
            while (0 <= l && r < sz && str[l] == str[r]) {
                l--;
                r++;
            };
            len[i] = r - i;
            mid = i;
        } else {
            int len_ = len[2 * mid - i];
            if (i + len_ < mid + len[mid]) {
                len[i] = len_;
                continue;
            } else {
                int l = 2 * i - (mid + len[mid]), r = mid + len[mid];
                while (0 <= l && r < sz && str[l] == str[r]) {
                    l--;
                    r++;
                }
                len[i] = r - i;
                mid = i;
            }
        }
    }

#ifdef Debug
    cout << str << endl;
    for (size_t i = 0; i < sz; ++i) {
        cout << len[i] << " ";
    }
#endif


    int max_len = 0, pos = -1;
    for (size_t i = 0; i < sz; ++i) {
        if (len[i] > max_len) {
            max_len = len[i];
            pos = i;
        }
    }
    string rs;
    for (size_t i = pos - len[pos] + 1; i < pos + len[pos]; ++i) {
        if (str[i] != '#') {
            rs.push_back(str[i]);
        }
    }
    return rs;
}


#ifdef Debug
int main() {
    Solution so;
    cout << so.longestPalindrome("abbbbccccbbddd") << endl;
    return 0;
}
#endif


