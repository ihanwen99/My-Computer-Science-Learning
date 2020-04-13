#include<iostream>
#include <algorithm>
using namespace std;


int main() {
	int i = 1;
	int& j1 = i;
	int& j2 = j1;

	cout << "int i = " << i << ", address = " << &i << endl;
	cout << "int& j1 = " << j1 << ", address = " << &j1 << endl;
	cout << "int& j2 = " << j1 << ", address = " << &j2 << endl;

	/*int i = 1, address = 005FF774
	int& j1 = 1, address = 005FF774
	int& j2 = 1, address = 005FF774*/
}
