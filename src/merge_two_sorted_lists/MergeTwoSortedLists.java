/**
 * Definition for singly-linked list.
 */
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }

    public String toString() {
        return "" + val;
    }
}

class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummy = new ListNode(-1);
        ListNode p = dummy;
//         while (l1 != null && l2 != null) {
//             if (l1.val < l2.val) {
//                 dummy.next = l1;
//                 l1 = l1.next;
//             } else {
//                 dummy.next = l2;
//                 l2 = l2.next;
//             }
//             dummy = dummy.next;
//         }
//
//         if (l1 != null) {
//             dummy.next = l1;
//         }
//
//         if (l2 != null) {
//             dummy.next = l2;
//         }

        while (l1 != null && l2 != null) {
            if (l1.val < l2.val) {
                p.next = l1;
                l1 = l1.next;
            } else {
                p.next = l2;
                l2 = l2.next;
            }
            p = p.next;
        }

        if (l1 != null) {
            p.next = l1;
        }

        if (l2 != null) {
            p.next = l2;
        }

        return dummy.next;
    }

    public void printListNode(ListNode head) {
        if (head == null) return;
        while (head != null) {
            System.out.print(head + " ");
            head = head.next;
        }
        System.out.println("");
    }
}

public class MergeTwoSortedLists {
    public static void main(String[] args) {
        ListNode l0 = new ListNode(1);
        ListNode l1 = new ListNode(2);
        ListNode l2 = new ListNode(4);
        ListNode l3 = new ListNode(1);
        ListNode l4 = new ListNode(3);
        ListNode l5 = new ListNode(4);
        l0.next = l1;
        l1.next = l2;
        l3.next = l4;
        l4.next = l5;

        Solution s = new Solution();
        s.printListNode(l0);
        s.printListNode(l3);
        ListNode res = s.mergeTwoLists(l0, l3);
        s.printListNode(res);
    }
}
