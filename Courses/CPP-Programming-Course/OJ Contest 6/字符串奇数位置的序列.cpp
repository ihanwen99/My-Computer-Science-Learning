#include <iostream>
using namespace std;

char* oddstr(char str[]);

int main() {
	char ss[] = "";
	char* result = oddstr(ss);
	cout << result << endl;
	return 0;
}

#include<cstring>
char* oddstr(char str[]) {
	int n = strlen(str);
	char* arr = new char[n / 2 + 1];
	int i = 0;
	for (; i < n; i++) {
		if (i % 2) { arr[i / 2] = str[i]; }
	}
	arr[n / 2] = '\0';
	return arr;
}