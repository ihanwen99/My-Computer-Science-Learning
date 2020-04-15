#include<iostream>
#include <algorithm>
using namespace std;


int main() {
	int* p, x;
	p = &x; cout << "p=&x: p = " << p << endl;
	p += 1; cout << "p+=1: p = " << p << endl;
}