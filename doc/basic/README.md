# Sorting algorithm

* 时间复杂度
* 空间复杂度
* stable
  * 稳定不稳定
* Sorting In-place

### Bubble Sort冒泡排序

* 比较相邻两数(repeatedly swapping the adjacent elements if they are in wrong order.)。

* ```c
  for (int i = 0; i < size - 1; i++)
      for (int j = 0; i < size - 1 - i; j++)
          if (arr[j] > arr[j+1])
          	swap(&arr[j], &arr[j+1]);
  ```

* ```c
  for (int i = 1; i < size; i++)
      for (int j = 1; j < size + 1 - i; j++)
          if (arr[j-1] > arr[j])
              swap(&arr[j-1], &arr[j]);
  ```

* size个数只需要比较size-1次。[0, size-1)匹配的是arr[j], arr[j+1] 同样arr[j-1], arr[j]可以使用[1, size)区间。

* 时间复杂度O(n^2)。空间复杂度O(1)。

* Stable: yes

* Sorting In Place: yes

### Selection Sort选择排序

* 选择最小的数(repeatedly finding the minimum element and putting it at the beginning; ascending order)

* ```c
  for (int i = 0; i < size - 1; i++) {
      min_idx = i;
      for (j = i + 1; j < size; j++)
          if(arr[j] < arr[min_idx])
              min_idx = j;
      swap(&arr[min_idx], &arr[i]);
  }
  ```

* 同理, size个数字只需要找出其中最小的size-1个。每次假设剩余数组中的第一个为最小，从`i+1`开始遍历，记录最小数的下标。

* 时间复杂度O(n^2)。空间复杂度O(1)。

* Sorting in place: yes

* Stable: the default implementation is not stable.

* ```c
  // stable selection sort
  for (int i = 0; i < size - 1; i++) {
  	int min = i;
  	for (int j = i + 1; j < size; j++)
  		if (arr[min] > arr[j])
  			min = j;
  	int key = arr[min];
  	while (min > i) {
  		a[min] = a[min - 1];
  		min--;
  	}
  	arr[i] = key;
  }
  ```

### Insertion Sort

* 维护一个有序的序列。

* ```c
  int i, key, j;
  for (i = 1; i < n; i++) {
      key = arr[i];
      j = i - 1;
      
      while (j >= 0 && arr[j] > key) {
          arr[j + 1] = arr[j];
          j = j - 1;
      }
      arr[j + 1] = key;
  }
  ```

* 第一个元素即有序 从下标1开始，找到此次元素所在的位置

* 时间复杂度O(n^2) 空间复杂度O(1)

* Sorting in place: yes

* Stable: yes

### Binary Insertion Sort

* 二分查找：

* ```c
  int binarySearch(int arr[], int item, int low, int high) {
      if (high <= low)
          return (item > arr[low]) ? (low + 1) : low;
      
      int mid = (low + high) / 2;
      
      if (item == arr[mid])
          return mid + 1;
      
      if (item > arr[mid])
          return binarySearch(arr, item, mid + 1, high);
      return binarySearch(arr, item, low, mid - 1);
  }
  ```

* 完整算法：

* ```c
  void insertionSort(int arr[], int size) {
      int i, loc, j, k, selected;
      
      for (i = 1; i < size; i++) {
          j = i - 1;
          selected = arr[i];
          
          loc = binarySearch(arr, selected, 0, j);
          
          while (j >= loc) {
              arr[j + 1] = arr[j];
              j = j - 1;
          }
          arr[j + 1] = selected;
      }
  }
  ```

### Merge Sort归并排序

* 合并两个有序的序列。(Divide and Conquer)

* ```c
  // arr[l..m], arr[m+1, r] 合并为 arr[l..r]
  void merge(int arr[], int l, int m, int r) {
      int i, j, k;
      int n1 = m - l + 1;
      int n2 = r - m;
      
      int L[n1], R[n2];
      
      for (i = 0; i < n1; i++)
          L[i] = arr[l + i];
      for (j = 0; j < n2; j++)
          R[j] = arr[m + 1 + j];
      
      i = 0;
      j = 0;
      k = l;
      while (i < n1 && j < n2) {
          /*if (L[i] <= R[j]) {
              arr[k] = L[i];
              i++;
          } else {
              arr[k] = R[j];
              j++;
          }
          k++;*/
          arr[k++] = L[i] < R[j] ? L[i++] : R[j++];
      }
      
      while (i < n1) {
          /*arr[k] = L[i];
          i++;
          k++;*/
          arr[k++] = L[i++];
      }
      
      while (j < n2) {
          /*arr[k] = R[j];
          j++;
          k++;*/
          arr[k++] = R[j++];
      }
  }
  
  void mergeSort(int arr[], int l, int r) {
      if (l < r) {
          int m = l + (r-1)/2;
          
          mergeSort(arr, l, m);
          mergeSort(arr, m+1, r);
          
          merge(arr, l, m, r);
    }
  }
  ```
  
* 时间复杂度O(nlogn) 空间复杂度O(n)

* Sorting in place: yes

* Stable: yes

### Heap Sort

* TODO

* ```cpp
  //  an index in arr[]. n is size of heap
  void heapify(int arr[], int n, int i) {
      int largest = i;  // initialize largest as root
      int left = 2*i + 1;
      int right = 2*i + 2;
      
      if (left < n && arr[left] > arr[largest])
          largest = left;
      
      if (right < n && arr[right]  > arr[largest])
          largest = right;
      
      // if the largest is not root
      if (largest != i) {
          swap(arr[i], arr[largest]);
          
          //  recursively heapify the affected sub-tree
          heapify(arr, n, largest);
      }
  }
  
  void heapSort(int arr[], int n) {
      //  build heap (rearrange array)
      for (int i = n / 2 - 1; i >= 0; i--)
          heapify(arr, n, i);
      
      for (int i = n - 1; i >= 0; i--) {
          //  move current root to end
          swap(arr[0], arr[i]);
          
          //  call max heapify on the reduced heap
          heapify(arr, i, 0)
      }
  }
  ```

* 时间复杂度TODO 空间复杂度TODO

* Sorting in place: yes

* Stable: NO

### QuickSort

* (Divide and Conquer)

* ```cpp
  int partition(int arr[], int low, int high) {
      int pivot = arr[high];
      int i = (low - 1);
      
      for (int j = low; j <= high - 1; j++) {
          if (arr[j] <= pivot) {
              i++;
              swap(&arr[i], &arr[j]);
          }
      }
      swap(&arr[i + 1], &arr[high]);
      return (i + 1);
  }
  
  void quickSort(int arr[], int low, int high) {
      if (low < high) {
          int pi = partition(arr, low, high);
          
          quickSort(arr, low, pi - 1);
          quickSort(arr, pi + 1, high);
      }
  }
  ```

* 时间复杂度 空间复杂度

* Sorting in-place: Yes for it doesn't require any extra storage

* Stable: NO

### Radix Sort

### Counting Sort

### Bucket Sort

### ShellSort