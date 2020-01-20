#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    friend ostream &operator<<(ostream &out, ListNode &node);
};

ostream &operator<<(ostream &out, ListNode &node) {

    out << "val: " << node.val << ", addr: " << &node;

    return out;
}

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2);
};


ListNode *Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL;
    ListNode **pTail = &head;
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            *pTail = l1;
            l1 = l1->next;
        } else {
            *pTail = l2;
            l2 = l2->next;
        }
        pTail = &(*pTail)->next;
    }
    *pTail = (l1 != NULL ? l1 : l2);
    return head;
}

void printListNode(ListNode *head) {
    if (head == NULL) return;
    ListNode *p = head;
    while (p != NULL) {
        cout << *p;
        p = p->next;
        if (p != NULL) {
            cout << " --> ";
        }
    }
    cout << endl;
}

ListNode *mergeSortedListsV2(ListNode *l1, ListNode *l2) {
    if (l1 == NULL || l2 == NULL) return NULL;
    ListNode dummy(-1);
    ListNode *p = &dummy;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }

    p->next = l1 != NULL ? l1 : l2;
    return dummy.next;
}

int main(int argc, char **argv) {

    ListNode l0(1), l1(2), l2(4), l3(1), l4(3), l5(4);
    l0.next = &l1;
    l1.next = &l2;
    l3.next = &l4;
    l4.next = &l5;

    printListNode(&l0);
    printListNode(&l3);

    Solution s;
    ListNode *p = s.mergeTwoLists(&l0, &l3);
    printListNode(p);

    return 0;
}
