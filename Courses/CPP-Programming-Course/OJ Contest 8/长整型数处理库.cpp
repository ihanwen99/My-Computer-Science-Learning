#include<iostream>
#include<cstring>
#include<deque>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int al = a.size(), bl = b.size();

	deque<int> result; int carry = 0;
	while (al > 0 || bl > 0) {
		int up = (al > 0) ? a[al - 1] - '0' : 0;
		int down = (bl > 0) ? b[bl - 1] - '0' : 0;
		int value = up + down + carry;
		result.push_front(value % 10);
		carry = value / 10;
		al--; bl--;
	}
	if (carry == 1) { result.push_front(1); }

	while (!result.empty()) {
		cout << result.front();
		result.pop_front();
	}
	cout << endl;

	return 0;
}