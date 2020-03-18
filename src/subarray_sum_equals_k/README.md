### subarray sum equals k

```
Given an array of integers and and integer k, you need to find the total number of continuous subarrays whose sum equals to k.

Example 1:
Input:nums = [1,1,1], k = 2
Output: 2
Note:
The length of the array is in range [1, 20,000].
The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
```

prefix sum数列前n项的和。
要求连续的子数组，即，prefixSum1-prefixSum2=k
所以prefixSum2=prefixSum1-k