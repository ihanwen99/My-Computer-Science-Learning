#include<iostream>
using namespace std;


void add_float(char* a, char* b, char* res);


int main() {
	char a[] = "0.1";
	char b[] = "0.9";
	char* res = a;
	add_float(a, b, res);
	cout << res << endl;
	return 0;
}

void split_float(char* a, long long& x, char*& y, int& ly) {
	x = 0; y = a;
	if (*y == '.') {
		x = 0;
	}
	else {
		while (*y != '.') {
			x = x * 10 + *y - '0';
			y++;
		}
	}
	y++;
	ly = strlen(y);
}

int add_wei(char*& ay, int al, char*& by, int bl) {
	if (al < bl) { return add_wei(by, bl, ay, al); }
	int carry = 0, temp; bool end = true;
	char* bt = new char[al + 1];
	for (int i = 0; i < bl; i++) { bt[i] = *by; by++; }for (int i = bl; i < al; i++) { bt[i] = '0'; }bt[al] = '\0';
	for (int i = al - 1; i >= 0; i--) {
		temp = ay[i] + bt[i] - '0' - '0' + carry;
		carry = temp / 10;
		if (temp % 10 == 0) {
			if (end == true) {
				ay[i] = '\0';
			}
			else { ay[i] = temp % 10 + '0'; }
		}
		else { ay[i] = temp % 10 + '0'; end = false; }
	}
	return carry;
}



// [IN] char* a, char* b: positive float number represented as string
// [OUT] char* res: result of a + b represented as string
void add_float(char* a, char* b, char* res) {
	char* head = res;
	long long ax, bx; char* ay, * by; int al, bl; int carry = 0;
	split_float(a, ax, ay, al);
	split_float(b, bx, by, bl);

	carry = add_wei(ay, al, by, bl);
	long long rx = ax + bx + carry;
	int length = 0;
	long long tempx = rx;
	while (tempx > 0) {
		length++;
		tempx /= 10;
	}
	if (length > 0) {
		for (int i = 0; i < length; i++) {
			*(head + length - 1 - i) = rx % 10 + '0';
			rx /= 10;
		}
	}  
	head = head + length;
	*head = '.'; head++;
	char* wei = (al >= bl) ? ay : by;
	int lengthw = strlen(wei);
	bool flag = false; char* temp = wei;
	for (int i = 0; i < lengthw; i++) { if (*temp != '0') { flag = true; break; }temp++; }
	if (flag) {
		while (*wei != '\0') {
			*head = *wei;
			head++; wei++;
		}
	}
	*head = '\0';
}