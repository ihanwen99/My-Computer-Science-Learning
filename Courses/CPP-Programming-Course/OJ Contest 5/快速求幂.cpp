#include <iostream>

using namespace std;

long long quickPow(int n, int k);

int main() {
	int n, k;
	cout << "Please input n: "; cin >> n;
	cout << "Please input k: "; cin >> k;

	cout << quickPow(n, k);
	return 0;
}

//递归的版本
long long quickPow(int n, int k) {
	if (k == 0) { return 1; }
	if (k == 1) { return n; }
	long long temp = quickPow(n, k / 2);
	if (k % 2 == 0) { return temp * temp; }
	return n * temp * temp;
}
