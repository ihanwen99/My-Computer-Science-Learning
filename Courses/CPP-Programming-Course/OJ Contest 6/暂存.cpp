#include<iostream>
#include<string>
using namespace std;

long long str_int(string s) {
	long long ans = 0;
	for (int i = 0; i < s.length(); i++) {
		ans = 10 * ans + s[i] - '0';
	}
	return ans;
}
int convert(int year, int month, int day) {
	int cal[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)cal[1] += 1;
	int ans = day;
	for (int i = 0; i < month - 1; i++) {
		ans += cal[i];
	}
	return ans;
}

bool getdate(int year, int x, int& month, int& day) {
  // Please fill this blank
	if (x > 366)return false;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)days[1] += 1;
	month = 1;
	while (x > days[month - 1]) {
		x -= days[month - 1];
		month += 1;
	}
	day = x;
	return true;
}

string int_date(int year, int month, int day) {
	string y = "", m = "", d = "";
	while (year > 0) {
		y = char('0' + year % 10) + y;
		year /= 10;
	}
	while (month > 0) {
		m = char('0' + month % 10) + m;
		month /= 10;
	}
	while (day > 0) {
		d = char('0' + day % 10) + d;
		day /= 10;
	}
	for (int i = 0; i < 4 - y.length(); i++)y = '0' + y;
	for (int i = 0; i < 2 - m.length(); i++)m = '0' + m;
	for (int i = 0; i < 2 - d.length(); i++)d = '0' + d;
	return y + m + d;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
	int year = (int)str_int(s1.substr(0, 4));
	int month = (int)str_int(s1.substr(4, 2));
	int day = (int)str_int(s1.substr(6, 2));
	long long days = str_int(s2) + convert(year, month, day);
	int thre;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)thre = 366;
	else thre = 365;
	while (days > thre) {
		days -= thre;
		year++;
		if (year > 9999) { cout << "out of limit!"; return 0; }
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)thre = 366;
		else thre = 365;
	}
	int f_m, f_day;
	getdate(year, (int)days, f_m, f_day);
	cout << int_date(year, f_m, f_day);
	return 0;
}
