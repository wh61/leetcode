//#define Debug

#ifdef Debug
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <stdexcept>
using namespace std;
#endif

class Solution {
public:
    vector<int> twoSum(vector<int>&, int);
};

vector<int> Solution::twoSum(vector<int> &numbers, int target) {
    size_t sz = numbers.size();
    if (sz < 2) {
        throw runtime_error("less than two elements");
    }
    size_t i = 0, j = sz - 1;
    vector<pair<int, size_t> > vec;
    for (size_t i = 0; i < sz; ++i) {
        vec.push_back(make_pair(numbers[i], i + 1));
    }
    sort(vec.begin(), vec.end());
    int ans_index1 = -1, ans_index2 = -1;
    while (i < j) {
        int num1 = vec[i].first, num2 = vec[j].first;
        int index1 = vec[i].second, index2 = vec[j].second;
        if (num1 + num2 == target) {
            ans_index1 = index1;
            ans_index2 = index2;
            break;
        } else if (num1 + num2 < target) {
            i++;
        } else {
            j--;
        }
    }
    if (ans_index1 > ans_index2) swap(ans_index1, ans_index2);
    if (ans_index1 == -1 && ans_index2 == -1) {
        throw runtime_error("No answer!");
    } else {
        int temp[] = {ans_index1, ans_index2};
        return vector<int>(temp, temp + 2);
    }
}

#ifdef Debug

int main() {
    Solution sl;
    int temp[] = {3, 2, 4};
    vector<int> numbers(temp, temp + 3);
    sl.twoSum(numbers, 6);
    return 0;
}

#endif
