#include <stdio.h>

void swap(int *xp, int *yp) {
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

void bubbleSort(int arr[], int size) {
	for (int i = 1; i < size; i++)
		for (int j = 1; j < size + 1 - i; j++)
			if (arr[j-1] > arr[j])
				swap(&arr[j-1], &arr[j]);
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int size = sizeof(arr)/sizeof(*arr);
	bubbleSort(arr, size);
	printf("Sorted array: \n");
	printArray(arr, size);
	return 0;
}
