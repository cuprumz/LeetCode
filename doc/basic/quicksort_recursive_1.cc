#include <iostream>

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++ ) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

void swap(int& xr, int& yr) {
	int tmp = xr;
	xr = yr;
	yr = tmp;
}

void quickSort(int arr[], int low, int high) {
	if(low >= high) {
		return ;
	}

	int pivot = arr[high];
	int left = low;
	int right = high - 1;

	// find pivot right position.
	while (left < right) {
		while (left < right && arr[left] < pivot)
			left++;
		while (left < right && arr[right] >= pivot)
			right--;
		swap(arr[left], arr[right]);
	}

	if (arr[left] > arr[high])
		swap(arr[left], arr[high]);
	else
		left++;
	
	quickSort(arr, low, left - 1);
	quickSort(arr, left + 1, high);
}

int main() {
	int arr[] = {9, 8, 7, 6, 5, 9, 9, 9, 9, 9, 4, 3, 2, 1, 0};
	int size = sizeof(arr) /sizeof(*arr);

	std::cout << "Original array: " << std::endl;
	printArray(arr, size);

	quickSort(arr, 0, size - 1);
	std::cout << "Sorted array: " << std::endl;
	printArray(arr, size);
	
	return 0;
}
