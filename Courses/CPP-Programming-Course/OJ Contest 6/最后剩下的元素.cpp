#include <iostream>
using namespace std;


int main() {
	int n; cin >> n;
	int* arr = new int[n];
	bool* left = new bool[n];
	for (int i = 0; i < n; i++) { arr[i] = i + 1; }
	for (int i = 0; i < n; i++) { left[i] = true; }

	int count = 0, idx = 0;
	while (count < n) {
		while (!left[idx]) { idx = (idx + 1) % n; }
		idx = (idx + 1) % n; while (!left[idx]) { idx = (idx + 1) % n; }
		idx = (idx + 1) % n; while (!left[idx]) { idx = (idx + 1) % n; }
		left[idx] = false;
		count++;
	}
	cout << arr[idx] << endl;

	delete[]arr;
	delete[]left;
	return 0;
}
