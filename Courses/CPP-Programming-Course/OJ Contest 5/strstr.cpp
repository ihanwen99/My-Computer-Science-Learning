#include<iostream>
using namespace std;


int mystrstr(char a[], char b[]);

int main() {
	//char a[] = "onlineJudge", b[] = "line";
	char a[] = "apple", b[] = "pen";
	cout << mystrstr(a, b);

	return 0;
}

int mystrstr(char a[], char b[]) {
	if (!a || !b) { return -1; }
	char* ap, * bp;
	int idx = 0;
	while (*a) {
		ap = a;
		bp = b;
		do {
			if (!*bp) { return idx; }
		} while (*ap++ == *bp++);
		a++; idx++;
	}
	return -1;
}