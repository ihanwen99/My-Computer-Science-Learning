#include <iostream>
using namespace std;

void f(char* a) {
	a = new char[10];
	strcpy(a, "123");
	cout << a << endl;
}

int main() {
	char* a = new char[10];
	strcpy(a, "abc");
	cout << a << endl;
	f(a);
	cout << a << endl;
	delete a;
	return 0;
}

// a=new char[10]; 
//不注释
//不会改变main函数的字符串

//注释掉的时候，就是同一块地址，会改变main中的字符串
