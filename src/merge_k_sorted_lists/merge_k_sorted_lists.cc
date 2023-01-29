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

    dummy.next = p1; // 假设p1.val小于p2.val
    ListNode *prev = &dummy;

    while (p1 && p2) {
        if (p1->val < p2->val) {
            // 假设为真
            // 1.记录前一个节点为p1
            prev = p1;
            // 2.然后p1后移
            p1 = p1->next;
        } else {
            // 假设错误 即p2.val小于等于p1.val
            // 1.下一节点为p2
            prev->next = p2;
            // 2.p2后移
            p2 = p2->next;
            // 3.prev后移 效果即prev为新连接的p2节点
            prev = prev->next;
            // 4.假设p1.val<p2.val
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

    // p1 p2的剩余节点
    ListNode *p = NULL;
    if (p1) {
        p = p1;
    } else if (p2) {
        p = p2;
    }

    // p1 或者 p2 有一个为空
    if (pHead == NULL) {
        return p;
    }

    // 连接剩余节点
    pTail->next = p;
    return pHead;
}

// 处理p的第一个节点
void TakeOutNode(ListNode *&head, ListNode *&tail, ListNode *&p) {
    ListNode *pNext = p->next;
    // head头节点 tail尾节点
    if (head == NULL) {
        head = tail = p; // 初始化头尾节点
    } else {
        tail->next = p; // 操作尾节点指针 连接
        tail = p; // 尾节点后移
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
