#define DEBUG
#ifdef DEBUG
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#endif


struct Obj {
    int x, y;
    Obj(int x_ = 0, int y_ = 0):x(x_), y(y_) {}
    friend bool operator< (const Obj&, const Obj&);
};

bool operator<(const Obj& a, const Obj& b) {
    return a.y < b.y;
}

bool operator<(int val, const Obj& o) {
    return val < o.y;
}


class Solution {
public:
    int maxArea(vector<int> &);
private:
    int getFromOne2Other(const vector<int> &);
};

int Solution::maxArea(vector<int> &height) {
    int ans = getFromOne2Other(height);
    reverse(height.begin(), height.end());
    ans = max(ans, getFromOne2Other(height));
    return ans;
}



int Solution::getFromOne2Other(const vector<int> &height) {
    int sz = height.size();
    vector<Obj> v;
    int ans = 0;
    for (size_t i = 0; i < sz; ++i) {
        if (v.empty()) {
            v.push_back(Obj(i, height[i]));
        } else {
            int h = height[i];
            vector<Obj>::iterator iter = lower_bound(v.begin(), v.end(), Obj(i, h));
            if (iter != v.end()) {
                ans = max(ans, (int)(i - iter->x) * h);
            }
            if (h > v[(int)v.size() - 1].y) {
                v.push_back(Obj(i, h));
            }
        }
    }
    return ans;
}


#ifdef DEBUG
int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    vector<int> v(a, a + 6);
    Solution sl;
    cout << sl.maxArea(v) << endl;
    return 0;
}
#endif
