#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

void selectionSort(int arr[], int size)
{
	int i, j, min_idx;
	for (i = 0; i < size - 1; i++)
	{
		min_idx = i;
		for (j = i+1; j < size; j++)
			if (arr[j] < arr[min_idx])
				min_idx = j;
		swap(&arr[min_idx], &arr[i]);
	}
}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	int size = sizeof(arr)/sizeof(*arr);
	cout << "Original array: \n";
	printArray(arr, size);
	selectionSort(arr, size);
	cout << "Sorted array: " << endl;
	printArray(arr, size);

	return 0;
}
