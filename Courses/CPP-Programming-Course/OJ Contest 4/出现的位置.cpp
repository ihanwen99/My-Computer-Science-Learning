#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n, x;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> x;

	int idxFirst = -1, idxLast = -1;
	if (x < arr[0]) { cout << -1 << ' ' << -1 << endl; return 0; }
	if (x > arr[n - 1]) { cout << -1 << ' ' << -1 << endl; return 0; }
	for (int i = 0; i < n; i++) {
		if (x == arr[i]) {
			if (idxFirst == -1) {
				idxFirst = i; idxLast = i;
			}
			else { idxLast = i; }
		}
	}
	cout << idxFirst << ' ' << idxLast;

	return 0;
}
