#include<iostream>
#include<algorithm>
using namespace std;


bool perfectnum(int x);

int main() {
	int a, b; cin >> a >> b;
	bool exist = false;
	for (int i = a; i <= min(b,8128); i++) {
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
	int sumTotal = 1, i = 2;
	for (; i * i < x; i++) {
		if (x % i == 0) {
			sumTotal += (i + x / i);
			if (x < sumTotal) { return false; }//提前退出
		}
	}
	if (i * i == x) { sumTotal += i; }
	return sumTotal == x;
}