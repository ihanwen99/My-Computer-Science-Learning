#include <iostream>
using namespace std;

int main() {
	char* str[10];
	//for (int i = 0; i < 10; i++) { cin >> str[i]; }//错误是没分配空间

	//我们为str分配了空间
	//但是我们没有为str[i]分配空间
	//下面分配空间,并传入
	//for (int i = 0; i < 10; i++) { str[i] = new char[10]; }
	//for (int i = 0; i < 10; i++) { cin >> str[i]; }

	//如果觉得上面的new浪费空间，可以使用根据长度来分配
	char temp[100];
	for (int i = 0; i < 10; i++) {
		cin >> temp; str[i] = new char[strlen(temp) + 1];
		//str[i] = temp;//这样是不行的
		strcpy(str[i], temp);
	}


//输出
	for (int i = 0; i < 10; i++) { cout << str[i] << endl; }
	return 0;
}
