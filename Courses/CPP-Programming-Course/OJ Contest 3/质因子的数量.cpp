#include <iostream>
using namespace std;

int main() {
	int n, p;
	cin >> n >> p;

	int count = 0, i = 1;
	while (p * i <= n) {
		int temp = i;
		while (temp % p == 0) { count += 1; temp /= p; }
		count += 1;
		i += 1;
	}
	cout << count << endl;
	return 0;
}