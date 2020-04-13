#include<iostream>
#include <algorithm>
using namespace std;

int num;
void f(int i) {
	if (i == 4) {
		cout << "finish" << endl;
		return;
	}
	for (num = 0; num < 3; num++) {
		cout << num << endl;
		i++;
		if (num % 2)f(i);
		i--;
	}
}

int main() {
	f(1);
	return 1;
}