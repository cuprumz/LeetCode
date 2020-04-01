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

/**
 * head指针 指向头节点
 * 改变二级指针的指向，使得*pTail每次指向下一个位置
 */
ListNode *Solution::mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = NULL;
    ListNode **pTail = &head; // 准备好头节点的位置
    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            *pTail = l1;
            l1 = l1->next;
        } else {
            *pTail = l2; // l2赋值给head, 使得head指向l2所指向的节点
            l2 = l2->next; // l2->next赋值给l2, 使得l2指向l2->next所指向的节点
        }
        pTail = &(*pTail)->next; // pTail指向head->next 下一次改变*pTail相当于 在已经排序的链后面挂上
    }
    *pTail = (l1 != NULL ? l1 : l2); // 挂上剩下的
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
    ListNode *p = &dummy; // p->next is ready

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            p->next = l1;
            l1 = l1->next;
        } else {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next; // p move next
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
//    ListNode *p = mergeSortedListsV2(&l0, &l3);
    printListNode(p);

    return 0;
}
