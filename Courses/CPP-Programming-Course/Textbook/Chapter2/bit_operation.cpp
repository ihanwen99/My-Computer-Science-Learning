#include<iostream>
#include <algorithm>
using namespace std;



int main() {
	cout << (4 & 6) << endl;//4 
	cout << (4 | 6) << endl;//6
	cout << (4 ^ 6) << endl;//2

	int a = 4, b = 6;
	cout << "Originally, a=" << a << ", b=" << b << endl;
	//swap(a,b)
	a ^= b; b ^= a; a ^= b;
	cout << "After swap, a=" << a << ", b=" << b << endl;

	//按位取反
	cout << (~6) << endl;//-7
	cout << (~- 7) << endl;//6

	//左移右移
	int leftShift = a << 1; cout << leftShift << endl;//6->12
	int rightShift = b >> 1; cout << rightShift << endl;//4->2

	//2的n次方
	cout << (1 << 10) << endl;//1024
	return 0;
}