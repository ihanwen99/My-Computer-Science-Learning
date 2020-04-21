#include <iostream>
using namespace std;

int main() {
	//指针指向的对象不发生改变：指向const int的指针
	//两者等价
	int const* p;
	const int* q;
	
	//指针自己是一个常量
	// * 在 const 前面
	int a = 3;
	int* const j = &a;
	return 0;
}
