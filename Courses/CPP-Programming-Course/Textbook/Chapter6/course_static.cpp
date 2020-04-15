#include<iostream>
#include <algorithm>
using namespace std;

int b = 10;
void foo(int b = 10) {
	static int a = 1;
	cout << b++ << endl;
	cout << ++a << endl;
}

int main() {
	int a = 1;
	foo(); a++; b++;
	foo(b); cout << b << endl;
	return 0;
}