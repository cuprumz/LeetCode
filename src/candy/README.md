### Candy

```
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

Example 1:

Input: [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.
Example 2:

Input: [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
             The third child gets 1 candy because it satisfies the above two conditions.
```

参考[haoel/leetcode](https://github.com/haoel/leetcode)

```
 *    The soluiton is O(2n) run-time complexity
 *
 *    For example:
 *
 *        ratings[] = { 5, 6, 7, 4, 1, 2, 3, 2, 1, 7 } 
 *
 *    1) Go through the ratings from left to right.
 *
 *       Find the each increasing sub-array, giving the minimal candy     
 *
 *        ratings[] = { 5, 6, 7,   4,   1, 2, 3,   2,   1, 7 } 
 *                      ------>    ->   ------>    ->   --->
 *          candy[] = { 1, 2, 3,   1,   1, 2, 3,   1,   1, 2 }
 *
 *    2) Go through the raings from right to left.
 *
 *             ratings[] = { 5,   6,   7, 4, 1,   2,   3, 2, 1,   7 } 
 *                           <-   <-   <------    <-   <------    <-
 *          prev_candy[] = { 1,   2,   3, 1, 1,   2,   3, 1, 1,   2 }
 *                                        +1              +1
 *               candy[] = { 1,   2,   3, 2, 1,   2,   3, 2, 1,   2 }
 *
 *    3) total candy is 19
 ```
