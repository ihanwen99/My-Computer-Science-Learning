#include <iostream>

#include <cstring>

using namespace std;

// 写出两个函数的声明
char*& funA(char**& p) {
	p = new char*;
	return *p;
}

char* funB(char* b, char** p) {
	for (int i = 0; i < 100; i++) {
		if (*((*p) + i) >= 'a' && *((*p) + i) <= 'z') {
			*(b + i) = *((*p) + i) + 'A' - 'a';
		}
		else { *(b + i) = *((*p) + i); }
	}
	delete p;
	return b;
}

int main() {
	char a[100], b[100];
	for (int i = 0; i < 3; ++i) {
		char** p;
		cin >> a;
		funA(p) = a;
		cout << funB(b, p) << endl;
	}

	return 0;
}

