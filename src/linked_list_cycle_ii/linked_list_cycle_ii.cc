#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    friend ostream &operator<<(ostream &out, ListNode *listNode);
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head);
};

ListNode *Solution::detectCycle(ListNode *head) {
    if (head == NULL || head->next == NULL) return NULL;

    ListNode *firstp = head;
    ListNode *secondp = head;
    bool isCycle = false;

    while (firstp != NULL && secondp != NULL) {
        firstp = firstp->next;
        if (secondp->next == NULL) return NULL;
        secondp = secondp->next->next;
        if (firstp == secondp) {
            isCycle = true;
            break;
        }
    }

    if (!isCycle) return NULL;
    firstp = head;
    while (firstp != secondp) {
        firstp = firstp->next;
        secondp = secondp->next;
    }

    return firstp;
}

ostream &operator<<(ostream &out, ListNode *listNode) {
    if (listNode == NULL) {
        return out;
    }
    out << "val: " << listNode->val << ", next: " << &listNode->next;
    return out;
}

int main(int argc, char **argv) {
    ListNode l1(3), l2(2), l3(0), l4(-4);
    l1.next = &l2;
    l2.next = &l3;
    l3.next = &l4;
    l4.next = &l2;

    Solution s;
    cout << s.detectCycle(&l1) << endl;

    ListNode l5(1), l6(2);
    l5.next = &l6;
    l6.next = &l5;
    cout << s.detectCycle(&l5) << endl;

    ListNode l7(1);
    cout << s.detectCycle(&l7) << endl;

    return 0;
}
