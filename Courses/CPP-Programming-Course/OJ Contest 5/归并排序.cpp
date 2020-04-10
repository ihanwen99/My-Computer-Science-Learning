#include <iostream>
using namespace std;

void mergeSort(int arr[], int low, int high);
void merge(int arr[], int low, int mid, int high);

int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	mergeSort(arr, 0, n - 1);

	for (int i = 0; i < n - 1; i++) { cout << arr[i] << ' '; }cout << arr[n - 1];

	return 0;
}


void mergeSort(int arr[], int low, int high) {
	if (high > low) {
		int mid = (low + high) / 2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
	}
}

void merge(int arr[], int low, int mid, int high) {
	int i = low, j = mid + 1, k = 0;
	int* temp = new int[high - low + 1];
	while (i <= mid && j <= high) {
		if (arr[i] < arr[j]) { temp[k++] = arr[i++]; }
		else { temp[k++] = arr[j++]; }
	}
	while (i <= mid) { temp[k++] = arr[i++]; }
	while (j <= high) { temp[k++] = arr[j++]; }
	for (i = low, k = 0; i <= high; i++) { arr[i] = temp[k++]; }
	delete[]temp;
}