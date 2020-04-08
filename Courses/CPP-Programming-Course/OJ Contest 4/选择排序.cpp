#include<iostream>
using namespace std;

int main() {
	int length; cin >> length;
	int* arr = new int[length];
	for (int i = 0; i < length; i++) { cin >> arr[i]; }

	int left, right, minIdx, temp;
	for (left = 0; left < length; left++) {
		minIdx = left;
		for (right = left; right < length; right++) {
			if (arr[right] < arr[minIdx]) {
				minIdx = right;
			}
		}
		temp = arr[minIdx];
		arr[minIdx] = arr[left];
		arr[left] = temp;
	}

	for (int i = 0; i < length; i++) {
		cout << arr[i] << ' ';
	}

	return 0;
}