### Rotate Image

```
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:
Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

Example 2:
Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 
rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
```

参考[haoel/leetcode](https://github.com/haoel/leetcode)


[i,j], [n-j-1,i], [n-j-1,n-i-1], [j,n-i-1],

```
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],
n=3;
i=0,j=0  => [0, 0],[2,0],[2,2],[0,2]

[
  [7,2,1],
  [4,5,6],
  [9,8,3]
],
i=0,j=1  => [0,1],[1,0],[1,2],[1,2]

[
  [7,4,1],
  [8,5,2],
  [9,6,3]
],

```

```
  1*  2   3   4*
  5   6   7   8 
  9  10  11  12 
 13* 14  15  16* 

 13   2*  3   1 
  5   6   7   8* 
  9* 10  11  12 
 16  14  15*  4 

 13   9   3*  1 
  5*  6   7   2 
 15  10  11  12*
 16  14*  8   4 

 13   9   5   1 
 14   6*  7*  2 
 15  10* 11*  3 
 16  12   8   4 

 13   9   5   1 
 14  10   6   2 
 15  11   7   3 
 16  12   8   4 

 13   9   5   1 
 14  10   6   2 
 15  11   7   3 
 16  12   8   4 
```

关键在于找到每个位置关于旋转的对应位置
[i, j]关于n*n的对称性分别为
[i,j], [n-j-1,i], [n-j-1,n-i-1], [j,n-i-1],
