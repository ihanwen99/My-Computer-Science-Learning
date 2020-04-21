#include <iostream>
using namespace std;

int main() {
	int* arr = new int[10];
	cout << sizeof(arr) << endl;//4

	char* crr = new char[10];
	cout << sizeof(crr) << endl;//4

	int arrINT[10];
	cout << sizeof(arrINT) << endl;//40

	double arrDOUBLE[10];
	cout << sizeof(arrDOUBLE) << endl;//80

	int* arrINTP[10];//数组的每个成员是一个指向int的指针
	cout << sizeof(arrINTP) << endl;//40

	char* String[10];//数组的每个成员是一个指向字符的指针
	cout << sizeof(String) << endl;//40

	double* arrDP[10];//数组的每个成员是一个指向double的指针
	cout << sizeof(arrDP) << endl;//40

	return 0;
}
