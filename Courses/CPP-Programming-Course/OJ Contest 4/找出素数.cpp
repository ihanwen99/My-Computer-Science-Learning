#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	long long n;
	cin >> n;

	bool* arr = new bool[n + 1];
	for (long long i = 2; i <= n; i++) { arr[i] = true; }

	for (long long i = 2; i * i <= n; i++) {
		if (arr[i]) {
			for (long long j = i; i * j <= n; j++) {
				arr[i * j] = false;
			}
		}
	}
	for (long long i = 2; i <= n; i++) {
		if (arr[i]) {
			cout << i << ' ';
		}
	}
	return 0;
}
