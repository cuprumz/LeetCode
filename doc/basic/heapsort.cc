#include <iostream>

using namespace std;

void swap(int &x, int &y) {
	int tmp = x;
	x = y;
	y = tmp;
}

void heapify(int arr[], int n, int i) {
	int largest = i;
	int left = 2*i + 1;
	int right = 2*i + 2;

	if (left < n && arr[left] > arr[largest])
		largest = left;

	if (right < n && arr[right] > arr[largest])
		largest = right;

	if (largest != i) {
		swap(arr[i], arr[largest]);

		heapify(arr, n, largest);
	}
}

void heapSort(int arr[], int n) {
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	for (int i = n - 1; i >= 0; i--) {
		swap(arr[0], arr[i]);

		heapify(arr, i, 0);
	}
}

void printArray(int arr[], int n) {
	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int n = sizeof(arr) / sizeof(*arr);
	cout << "Original array: " << endl;
	printArray(arr, n);

	heapSort(arr, n);

	cout << "Sorted array: " << endl;
	printArray(arr, n);
}
