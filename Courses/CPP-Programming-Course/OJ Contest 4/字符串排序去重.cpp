#include<iostream>
using namespace std;

int main() {
	char input[81]; cin.getline(input, 80, cin.eof());
	for (char ord = 126; ord >= 32; ord--) {
		bool flag = false;
		for (int i = 0; i <= 80 && input[i] != '\0'; i++) {
			if (ord == input[i]) { flag = true; break; }
		}
		if (flag) { cout << ord; }
	}

	return 0;
}