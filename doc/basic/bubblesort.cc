#include <bits/stdc++.h>
using namespace std;

void swap(int *xp, int *yp)
{
	int tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)
		for (j = 0; j < n-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
	int n = sizeof(arr) / sizeof(*arr);
	bubbleSort(arr, n);
	cout << "Sorted array: \n";
	printArray(arr, n);
	return 0;
}
