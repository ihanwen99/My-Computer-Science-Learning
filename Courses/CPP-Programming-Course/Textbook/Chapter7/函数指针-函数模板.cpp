#include <iostream>
using namespace std;

int main() {
	//函数名也是一个指针
	void(*func[4])() = [NULL, add, erease, modify];
	return 0;
}
