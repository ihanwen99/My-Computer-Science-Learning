#include<iostream>
#include <algorithm>
using namespace std;

void max2(int a[], int n, int* first, int* second);

int main() {
	int n; cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) { cin >> arr[i]; }

	int first, second;
	max2(arr, n, &first, &second);
	cout << first << ' ' << second << endl;
}

void max2(int a[], int n, int* first, int* second) {
	switch (n) {
	case 1:*first= a[0]; return;
	case 2:
		if (a[0] == a[1]) { *first = a[0]; return; }
		*first = max(a[0], a[1]); *second = min(a[0], a[1]); return;
	default:
		int max0, second0, max1, second1;
		max2(a, n / 2, &max0, &second0);
		max2(a + n / 2, n - n / 2, &max1, &second1);
		if (max0 > max1) { *first = max0; *second = max(second0, max1); }
		if (max1 > max0) { *first = max1; *second = max(second1, max0); }
		if (max1 == max0) { *first = *second = max0; }
		return;
	}
}