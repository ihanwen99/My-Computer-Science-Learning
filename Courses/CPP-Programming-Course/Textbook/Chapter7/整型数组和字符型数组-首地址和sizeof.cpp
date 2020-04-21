#include <iostream>
using namespace std;

int main() {
	int a[5] = { 1,2,3,4 };
	char b[10] = "hello";
	cout << a << '\t' << sizeof(a) << endl; //address 20=5*4
	cout << b << '\t' << sizeof(b) << endl; //hello(string) 10=10*1
	cout << strlen(b) << endl;

	return 0;
}

