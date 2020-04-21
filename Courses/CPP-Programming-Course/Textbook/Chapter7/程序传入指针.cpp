#include <iostream>
using namespace std;

void f(char* a) {
	char* b = new char[10];
	b[0] = 'f'; b[1] = '\0';
	a = b;
	cout << a << endl;
}

int main() {
	char a[] = "abcde";//a的空间是 a b c d e \0
	f(a); //传递过去只是地址
	cout << a << endl;
	return 0;

	//输出
	//f
	//abcde
}

