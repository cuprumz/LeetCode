### merge two sorted lists

```
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.

Example:

Input: 1->2->4, 1->3->4
Output: 1->1->2->3->4->4
```


```c++
l1 = l1->next; // 在链表l1上移动
```

```c++
l2 = l2->next; // 同理，在l2上移动
```

dummy变量，固定地址的一块内存。

p指针变量，（固定地址的一块内存）但是通过dereference可以操作不同地址的内存
