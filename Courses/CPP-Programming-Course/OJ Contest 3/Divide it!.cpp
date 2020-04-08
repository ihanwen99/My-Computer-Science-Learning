#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	//时刻小心溢出的问题 10^18
	long long n, count = 0;
	cin >> n;

	while (n % 5 == 0) {
		n /= 5;
		n *= 4;
		count++;
	}

	while (n % 3 == 0) {
		n /= 3;
		n *= 2;
		count++;
	}

	while (n % 2 == 0) {
		n /= 2;
		count++;
	}

	if (n == 1) { cout << count << endl; }
	else { cout << -1 << endl; }

	return 0;
}
