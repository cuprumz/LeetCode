#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}

    friend ostream &operator<<(ostream &out, ListNode &node);
};

ostream &operator<<(ostream &out, ListNode &node) {

    out << "addr: " << &node << ", val: " << node.val;

    return out;
}

ListNode *mergeTwoLists(ListNode *p1, ListNode *p2);

ListNode *mergeTwoLists01(ListNode *p1, ListNode *p2);

ListNode *mergeTwoLists02(ListNode *p1, ListNode *p2);

ListNode *mergeKLists(vector<ListNode *> &lists) {
    ListNode *p, *p1, *p2;
    while (lists.size() > 1) {
        p1 = lists.back();
        lists.pop_back();
        p2 = lists.back();
        lists.pop_back();
        p = mergeTwoLists(p1, p2);
        lists.insert(lists.begin(), p);
    }
    return lists.size() == 1 ? lists[0] : NULL;
}

static int n = 0;

ListNode *mergeTwoLists(ListNode *head1, ListNode *head2) {
    if (n) {
        return mergeTwoLists01(head1, head2);
    }
    return mergeTwoLists02(head1, head2);
}

ListNode *mergeTwoLists01(ListNode *head1, ListNode *head2) {
    ListNode *p1 = head1, *p2 = head2;
    static ListNode dummy(0);

    dummy.next = p1;
    ListNode *prev = &dummy;

    while (p1 && p2) {
        if (p1->val < p2->val) {
            prev = p1;
            p1 = p1->next;
        } else {
            prev->next = p2;
            p2 = p2->next;
            prev = prev->next;
            prev->next = p1;
        }
    }
    if (p2) {
        prev->next = p2;
    }
    return dummy.next;
}

void TakeOutNode(ListNode *&head, ListNode *&tail, ListNode *&p);

ListNode *mergeTwoLists02(ListNode *head1, ListNode *head2) {
    ListNode *p1 = head1, *p2 = head2;
    ListNode *pHead = NULL, *pTail = NULL;
    while (p1 && p2) {
        if (p1->val < p2->val) {
            TakeOutNode(pHead, pTail, p1);
        } else {
            TakeOutNode(pHead, pTail, p2);
        }
    }

    ListNode *p = NULL;
    if (p1) {
        p = p1;
    } else if (p2) {
        p = p2;
    }
    if (pHead == NULL) {
        return p;
    }
    pTail->next = p;
    return pHead;
}

void TakeOutNode(ListNode *&head, ListNode *&tail, ListNode *&p) {
    ListNode *pNext = p->next;
    if (head == NULL) {
        head = tail = p;
    } else {
        tail->next = p;
        tail = p;
    }
    p->next = NULL;
    p = pNext;
}

void printListNode(ListNode *head) {
    if (head == NULL) return;
    cout << "  h:";
    ListNode *p = head;
    while (p != NULL) {
        cout << *p;
        p = p->next;
        if (p != NULL) {
            cout << " \n--> ";
        }
    }
    cout << endl;
}

ListNode *createList(int *a, int n) {
    ListNode *head = NULL, *p = NULL;
    for (int i = 0; i < n; i++) {
        if (head == NULL) {
            head = p = new ListNode(*(a + i));
        } else {
            p->next = new ListNode(*(a + i));
            p = p->next;
        }
    }
    return head;
}

int main(int argc, char **argv) {

    srand(time(0));
    if (argc > 1) {
        n = atoi(argv[1]) % 2;
    }

    int a[] = {1, 3, 5, 6, 7, 10};
    int b[] = {0, 4, 6, 8, 9, 11, 20, 30, 40};
    ListNode *p1 = createList(a, sizeof(a) / sizeof(int));
    ListNode *p2 = createList(b, sizeof(b) / sizeof(int));

    printListNode(mergeTwoLists(p1, p2));

    vector<ListNode *> v;
    for (int i = 0; i < 10; i++) {
        v.push_back(new ListNode(random() % 100));
    }
    printListNode(mergeKLists(v));

    return 0;
}
