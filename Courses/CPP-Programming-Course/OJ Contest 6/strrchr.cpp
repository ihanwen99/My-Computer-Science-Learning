#include <iostream>
using namespace std;

const char* strrchr(const char* str, int ch);

int main() {
	char input[] = "/home/user/hello.c";
	char* output = strrchr(input, '/');
	if (output) { cout << output + 1 << '\n'; }

	return 0;
}

const char* strrchr(const char* str, int ch) {
	if (str == NULL) { return NULL; }
	char* p = NULL;
	while (*str != '\0') {
		if (*str == (char)ch) { p = (char*)str; }
		str++;
	}
	return p;
}
