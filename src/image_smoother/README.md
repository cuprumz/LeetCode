### image smoother

```
An image smoother is a filter of the size 3 x 3 that can be applied to each cell of an image by rounding down the average of the cell and the eight surrounding cells (i.e., the average of the nine cells in the blue smoother). If one or more of the surrounding cells of a cell is not present, we do not consider it in the average (i.e., the average of the four cells in the red smoother).
Given an m x n integer matrix img representing the grayscale of an image, return the image after applying the smoother on each cell of it.
```

rounding down: 向下取整

wrong.rs: 没有考虑小于3的情况

如何把特殊情况一般化，而不是一味的分情况讨论 枚举