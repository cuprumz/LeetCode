#include <stdio.h>
#include <stdlib.h>

struct MaxHeap {
	int size;
	int* array;
};

void swap(int* xp, int* yp) {
	int t = *xp;
	*xp = *yp;
	*yp = t;
}

void maxHeapify(struct MaxHeap* maxHeap, int idx) {
	int largest = idx;
	int left = (idx << 1) + 1;
	int right = (idx + 1) << 1;

	if (left < maxHeap->size && 
			maxHeap->array[left] > maxHeap->array[largest])
		largest = left;

	if (right < maxHeap->size &&
			maxHeap->array[right] > maxHeap->array[largest])
		largest = right;

	if (largest != idx) {
		swap(&maxHeap->array[largest], &maxHeap->array[idx]);
		maxHeapify(maxHeap, largest);
	}
}

struct MaxHeap* createAndBuildHeap(int* array, int size) {
	int i;
	struct MaxHeap* maxHeap = (struct MaxHeap*) malloc(sizeof(struct MaxHeap));
	maxHeap->size = size;
	maxHeap->array = array;

	for (i = (maxHeap->size - 2) / 2; i >= 0; i--)
		maxHeapify(maxHeap, i);
	return maxHeap;
}

void heapSort(int* array, int size) {
	struct MaxHeap* maxHeap = createAndBuildHeap(array, size);

	while (maxHeap->size > 1) {
		swap(&maxHeap->array[0], &maxHeap->array[maxHeap->size - 1]);
		--maxHeap->size;
		maxHeapify(maxHeap, 0);
	}
}

void printArray(int* arr, int size) {
	int i;
	for (i = 0; i < size; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int size =  sizeof(arr) / sizeof(*arr);

	printf("Original array: ");
	printArray(arr, size);

	heapSort(arr, size);
	printf("Sorted array: ");
	printArray(arr, size);

	return 0;
}


