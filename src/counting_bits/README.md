### Counting Bits

```
Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.

Example 1:
Input: 2
Output: [0,1,1]

Example 2:
Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss? Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
```

参考[haoel/leetcode](https://github.com/haoel/leetcode)

bits_cnt[x] = bits_cnt[x & (x-1) ] + 1;

0b0000  bits_cnt[0] = 0
0b0001  bits_cnt[1] = 1
0b0010  bits_cnt[2] = 1
0b0011
0b0100
0b0101
0b0110
0b0111
0b1000

基本情况 1bit
bits_cnt[0] = 0b0000 = 0
bits_cnt[1] = 0b0001 = 1

2bits
bits_cnt[2] = 0b0010 = 0b0010 + 0
bits_cnt[3] = 0b0011 = 0b0010 + 1

3bits
bits_cnt[4] = 0b0100 = 0b0100 + 0
bits_cnt[5] = 0b0101 = 0b0100 + 1
bits_cnt[6] = 0b0110 = 0b0100 + 2
bits_cnt[7] = 0b0111 = 0b0100 + 3


x & (x - 1)代表
1&0: 0
2&1: 0
3&2: 2
4&3: 0
5&4: 4
6&5: 4
7&6: 6
8&7: 0
9&8: 8
10&9: 8
11&10: 10
12&11: 8
13&12: 12
14&13: 12
15&14: 14
16&15: 0
17&16: 16
18&17: 16
19&18: 18