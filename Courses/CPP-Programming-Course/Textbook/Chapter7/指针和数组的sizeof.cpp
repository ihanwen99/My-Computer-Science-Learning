#include <iostream>
using namespace std;

int main() {
	int* arr = new int[10];
	cout << sizeof(arr) << endl;//4

	double arrDOUBLE[10];
	cout << arrDOUBLE << endl;//一个地址
	cout << sizeof(arrDOUBLE) << endl;//80

	double* arrDP[10];//数组的每个成员是一个指向double的指针
	cout << sizeof(arrDP) << endl;//40


	double* p;

	p = arrDOUBLE;
	cout << p << ' ' << sizeof(p) << endl;//4


	return 0;
}
