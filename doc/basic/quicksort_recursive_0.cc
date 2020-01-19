#include <iostream>

using namespace std;

void swap(int* xp, int* yp) {
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

int partition_1(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = low; // pointer to the right position.

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] <= pivot) {
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[i], &arr[high]);

	return i;
}

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
		int pivot = partition_1(arr, low, high);

		quickSort(arr, low, pivot - 1);
		quickSort(arr, pivot + 1, high);
	}
}

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int size = sizeof(arr) / sizeof(*arr);
	
	cout << "Original array: " << endl;
	printArray(arr, size);

	quickSort(arr, 0, size - 1);

	cout << "Sorted array: " << endl;
	printArray(arr, size);

	return 0;
}
