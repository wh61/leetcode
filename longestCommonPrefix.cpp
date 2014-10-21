#define DEBUG
#ifdef DEBUG
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

using namespace std;

#endif

class Solution {
public:
    string longestCommonPrefix(vector<string>&);
private:
    int longestCommonPrefix(const string&, const string&);
};

string Solution::longestCommonPrefix(vector<string> &strs) {
    size_t sz = strs.size();
    if (sz == 0) {
        throw runtime_error("string vector size is zero");
        return "";
    }
    int ans = strs[0].size();
    for (size_t i = 0; i + 1 < sz; ++i) {
        ans = min(ans, longestCommonPrefix(strs[i], strs[i + 1]));
    }
    string s = strs[0].substr(0, ans);
    return s;
}

int Solution::longestCommonPrefix(const string& s1,const string& s2) {
    size_t sz = min(s1.size(), s2.size());
    size_t lcp = 0;
    for (size_t i = 0; i < sz; ++i) {
        if (s1[i] == s2[i]) {
            lcp = i + 1;
        } else {
            break;
        }
    }
    return lcp;
}

#ifdef DEBUG
int main() {
    return 0;
}
#endif
