#include<iostream>
#include <algorithm>
using namespace std;

bool getdate(int x, int& month, int& day);

int main() {
	int x; cin >> x;
	int month, day;

	bool result = getdate(x, month, day);

	cout << month << ' ' << day << endl;
}

bool getdate(int x, int& month, int& day) {
	if (x > 366) { return false; }
	int monthDay[] = { 31,29,31,30,31,30,31,31,30,31,30,30,31 };
	for (month = 0; month < 12; ++month) {
		if (month == 11) { break; }
		if (x <= monthDay[month]) { break; }
		x -= monthDay[month];
	}
	month++; day = x;
	return true;
}