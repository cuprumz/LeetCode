### shortest subarray to be removed to make array sorted


Given an integer array `arr`, remove a subarray (can be empty) form `arr` such that the remaining elements in `arr` are **non-decreasing**.
Return the length of the shortest subarray to remove
A **subarray** is a contiguous subsequence of the array.

#### Constraints:
- 1 <= arr.length <= 10^5
- 0 <= arr[i] <= 10^9

#### Related Topics
Array,  Two Pointers,  Binary Search,  Stack,  Monotonic Stack

#### Hint
- The key is to find the longest non-decreasing subarray starting with the first element or ending with the last element, respectively.
- After removing some subarray, the result is the concatenation of a sorted prefix and a sorted suffix, where the last element of the prefix is smaller than the first element of the suffix.

#### submissions
- wrong.rs: [1,1,1,2,2,2] excepted 3 output 2
