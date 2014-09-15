#define Debug

#ifdef Debug
#include <iostream>
#include <stdexcept>
using namespace std;
#endif

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n);
private:
    int findKthNumber(int a[], int m, int b[], int n, int K);
};


double Solution::findMedianSortedArrays(int A[], int m, int B[], int n) {
    if (m + n == 0) {
        throw runtime_error("m + n == 0");
    }
    if ((m + n) & 1) {
        return findKthNumber(A, m, B, n, (m + n) / 2 + 1);
    } else {
        int leftMedian = findKthNumber(A, m, B, n, (m + n) / 2);
        int rightMedian = findKthNumber(A, m, B, n, (m + n) / 2 + 1);
        return ((double)leftMedian + (double)rightMedian) / 2;
    }
}


int Solution::findKthNumber(int a[], int m, int b[], int n, int K) {
    if (K == 1) {
        if (n == 0) {
            return a[0];
        } else if (m == 0) {
            return b[0];
        } else {
            return min(a[0], b[0]);
        }
    }
    int L = 0, R = 0;
    if (m < n) {
        L = min(m, K / 2), R = K - L;
    } else {
        R = min(n, K / 2), L = K - R;
    }
    if (L == 0) {
        return b[R - 1];
    } else if (R == 0) {
        return a[L - 1];
    } else if (a[L - 1] < b[R - 1]) {
        return findKthNumber(a + L, m - L, b, n, K - L);
    } else {
        return findKthNumber(a, m, b + R, n - R, K - R);
    }
}


#ifdef Debug

int main() {
    int A[] = {};
    int B[] = {2, 4, 6, 8, 10};
    Solution so;
    cout << so.findMedianSortedArrays(A, 0, B, 5) << endl;
    return 0;
}

#endif
