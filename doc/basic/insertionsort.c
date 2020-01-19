#include <stdio.h>

void insertionSort(int arr[], int size) {
	int i, val, j;
	for (i = 1; i < size; i++) {
		val = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > val) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = val;
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1,0};
	int size = sizeof(arr) / sizeof(*arr);
	printf("Original array:\n");
	printArray(arr, size);
	insertionSort(arr, size);
	printf("Sorted array:\n");
	printArray(arr, size);

	return 0;
}
