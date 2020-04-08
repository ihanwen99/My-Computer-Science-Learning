#include <iostream>
using namespace std;

void print(int n);

int main() {
	int n; cin >> n;
	print(n);

	return 0;
}

void print(int n) {
	int i, j;
	for (i = 1; i <= n; ++i) {
		for (j = 1; j <= n - i; ++j) { cout << " "; }
		for (j = 1; j <= 2 * i - 1; ++j) { cout << "*"; }
		cout << endl;
	}
}

void print(int n) {
	if (n == 0) { return; }
	static int space = n-1;
	print(n - 1);
	for (int i = 0; i < space; i++) { cout << ' '; }space--;
	for (int i = 0; i < 2 * n - 1; i++) { cout << "*"; }	 
	if(space>=0)cout << endl;
}


