#include <iostream>

using namespace std;

void printArray(int arr[], int size) {
	for (int i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void mergeSort(int arr[], int reg[], int start, int end) {
	if (start >= end) {
		return ;
	}

	int s1 = start;
	int e1 = start + ((end - start) >> 1);
	int s2 = e1 + 1;
	int e2 = end;

	mergeSort(arr, reg, s1, e1);
	mergeSort(arr, reg, s2, e2);

	int i = start;
	while (s1 <= e1 && s2 <= e2)
		reg[i++] = arr[s1] > arr[s2] ? arr[s2++] : arr[s1++];
	while (s1 <= e1)
		reg[i++] = arr[s1++];
	while (s2 <= e2)
		reg[i++] = arr[s2++];
	for (i = start; i <= end; i++)
		arr[i] = reg[i];
}

void merge_sort_recursive(int *arr, int *reg, int start, int end) {
    if (start >= end)
        return;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    merge_sort_recursive(arr, reg, start1, end1);
    merge_sort_recursive(arr, reg, start2, end2);
    int k = start;
    while (start1 <= end1 && start2 <= end2)
        reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
    while (start1 <= end1)
        reg[k++] = arr[start1++];
    while (start2 <= end2)
        reg[k++] = arr[start2++];
    for (k = start; k <= end; k++)
        arr[k] = reg[k];
}


int main() {
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int size = sizeof(arr) / sizeof(*arr);
	int reg[size];

	cout << "Original array: " << endl;
	printArray(arr, size);

	//merge_sort_recursive(arr, reg, 0, size - 1);
	mergeSort(arr, reg, 0, size - 1);

	cout << "Sorted array: " << endl;
	printArray(arr, size);

	return 0;
}
