### Reordered Power of 2

```
Starting with a positive integer N, we reorder the digits in any order (including the original order) such that the leading digit is not zero.

Return true if and only if we can do this in a way such that the resulting number is a power of 2.

 

Example 1:

Input: 1
Output: true
Example 2:

Input: 10
Output: false
Example 3:

Input: 16
Output: true
Example 4:

Input: 24
Output: false
Example 5:

Input: 46
Output: true
 

Note:

1 <= N <= 10^9
```

思路1: N小于32位，所以可以枚举出所有可能（不超过32个）。按位排序后，查找N是否在所有可能中


思路2:
Reference:[Discuss](https://leetcode.com/problems/reordered-power-of-2/discuss/149843/C%2B%2BJavaPython-Straight-Forward)

重新排序，与位置无关，所以每个位置的权重一致
power of 2: 简单的左移运算

简单的一个hash函数：counter
