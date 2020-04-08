#include <iostream>

using namespace std;

long long fib();

int main() {
	int times;
	cout << "Please input call times: "; cin >> times;
	for (int i = 0; i < times; i++) { cout << fib() << endl;; }

	return 0;
}

long long fib() {
	static long long a = 1;
	static long long b = 0;
	long long temp = a;
	a = a + b;
	b = temp;
	return b;
}
