#include <iostream>
using namespace std;

int main() {
	char s[2] = { 'A','B' };//A 65,B 66
	short* xx = (short*)s;//两个字节short -> 66*256+265 = 16961
	cout << *xx << endl;
	return 0;
}
