#include<iostream>
using namespace std;

int main() {
	char strInput[14]; cin >> strInput;
	long number1 = 0, number2 = 0;
	int operation_id = -1;
	bool operation_find = false;

	for (int i = 0; i < 14 && strInput[i] != '\0'; i++) {
		char target = strInput[i];
		if (target == '+' || target == '-' || target == '*' || target == '/') { operation_id = i; operation_find = true; continue; }
		if (operation_find == false) { number1 = number1 * 10 + (target - '0'); }
		else { number2 = number2 * 10 + (target - '0'); }
	}
	
	char operation = strInput[operation_id];
	switch (operation) {
	case '+':cout << number1 + number2 << endl; break;
	case '-':cout << number1 - number2 << endl; break;
	case '*':cout << number1 * number2 << endl; break;
	case '/':cout << number1 / number2 << endl; break;;
	}

	return 0;
}