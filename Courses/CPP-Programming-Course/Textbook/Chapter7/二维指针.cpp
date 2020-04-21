#include <iostream>
using namespace std;

int main() {
	int x = 15;
	int* p = &x;
	int** q = &p;

	const char* city[] = { "aaa","bbb","ccc" };
	const char** pointer;

	for (pointer = city; pointer < city + 3; ++pointer) { cout << *pointer << endl; }
	return 0;
}
