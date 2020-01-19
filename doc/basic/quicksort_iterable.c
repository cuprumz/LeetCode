#include <stdio.h>

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int* xr, int* yr) {
	int tmp = *xr;
	*xr = *yr;
	*yr = tmp;
}

typedef struct _Range {
	int start, end;
} Range;

Range new_Range(int s, int e) {
	Range r;
	r.start = s;
	r.end = e;

	return r;
}

void quickSort(int arr[], const int len) {
	if (len <= 0)
		return ;
	Range r[len];
	int p = 0;
	r[p++] = new_Range(0, len-1);
	while (p) {
		Range range = r[--p];
		if (range.start >= range.end)
			continue;
		int pivot = arr[(range.start + range.end) / 2];
		int left = range.start, right = range.end;
		do {
			while (arr[left] < pivot)
				++left;
			while (arr[right] > pivot)
				--right;
			if (left <= right) {
				swap(&arr[left], &arr[right]);
				left++;
				right--;
			}
		} while (left <= right);
		
		if (range.start < range.end) 
			r[p++] = new_Range(range.start, right);
		if (range.end > left)
			r[p++] = new_Range(left, range.end);
	}
}

int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0, 0, 1, 2, 3, 4, 5};
	int size = sizeof(arr)/sizeof(*arr);

	printf("Original array: \n");
	printArray(arr, size);

	quickSort(arr, size);
	printf("Sorted array: \n");
	printArray(arr, size);

	return 0;
}
