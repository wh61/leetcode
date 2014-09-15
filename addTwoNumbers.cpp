#define Debug

#ifdef Debug
#include <iostream>
using namespace std;
#endif

#ifdef Debug
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};
#endif

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2);
};

ListNode* Solution::addTwoNumbers(ListNode *l1, ListNode *l2) {
    int carryBit = 0;
    ListNode *ans = NULL, **p = &ans;
    while (carryBit != 0 || l1 != NULL || l2 != NULL) {
        int val = carryBit;
        if (l1 != NULL) {
            val += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL) {
            val += l2->val;
            l2 = l2->next;
        }
        if (val > 9) {
            carryBit = 1;
            val -= 10;
        } else {
            carryBit = 0;
        }
        *p = new ListNode(val);
        p = &((*p)->next);
    }
    return ans;
}

#ifdef Debug
int main() {

    return 0;
}
#endif


