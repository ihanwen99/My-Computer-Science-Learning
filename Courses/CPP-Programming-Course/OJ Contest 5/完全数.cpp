#include<iostream>
using namespace std;


bool perfectnum(int x);

int main() {
	int a, b; cin >> a >> b;
	bool exist = false;
	for (int i = a; i <= b; i++) {
		if (perfectnum(i)) {
			exist = true;
			cout << i << endl;
		}
	}
	if (!exist) { cout << "NONE" << endl; }

	return 0;
}

bool perfectnum(int x) {
	if (x == 1) { return false; }

	// sumTotal must contain 1.
	int sumTotal = 1;
	for (int i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			sumTotal += (i + x / i);
		}
	}
	return sumTotal == x;
}