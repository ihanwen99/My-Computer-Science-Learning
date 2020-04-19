#include <iostream>
using namespace std;

int monthDay[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
bool isLeapYear(int year);
int afterThisYearLeftDays(int year, int days);
int firstYearLeftDays(int year, int month, int day);
void calInThisYear(int month, int day, int days, int& finalMonth, int& finalDay);
void print(int year, int month, int day);

int main() {
	char date[9]; cin >> date;//需要多一位才能存储下，不能使用int，因为会去掉全面的0
	long long int days; cin >> days;

	int year = 0, month = 0, day = 0;
	for (int i = 0; i < 8; i++) {
		if (i < 4) { year = year * 10 + date[i] - '0'; }
		else {
			if (i < 6) { month = month * 10 + date[i] - '0'; }
			else { day = day * 10 + date[i] - '0'; }
		}
	}
	//cout << year << ' ' << month << ' ' << day << endl;

	int leftDays = firstYearLeftDays(year, month, day);
	int finalMonth, finalDay;

	//增加的天数不足以跨年，从当前日期开始增加
	if (days <= leftDays) {
		calInThisYear(month, day, days, finalMonth, finalDay); //cout << finalMonth << ' ' << finalDay << endl;
		print(year, finalMonth, finalDay);
		return 0;
	}

	//剩下的天数可以跨年，预先判断年份是否超期
	days -= leftDays; year++; if (year > 9999) { cout << "out of limit!"; return 1; }

	//不断跨年
	while (days > (365 + isLeapYear(year))) {
		days -= 365 + isLeapYear(year);
		year++; if (year > 9999) { cout << "out of limit!"; return 1; }
	}

	//余下天数不足以跨年，从新年第零天开始增加
	calInThisYear(1, 0, days, finalMonth, finalDay);
	print(year, finalMonth, finalDay);

	return 0;
}

bool isLeapYear(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int afterThisYearLeftDays(int year, int days) {
	return days - (365 + isLeapYear(year));
}

int firstYearLeftDays(int year, int month, int day) {
	int leftDays = -day;
	for (int monthID = month - 1; monthID < 12; monthID++) {
		leftDays += monthDay[monthID];
	}
	return leftDays;
}

void calInThisYear(int month, int day, int days, int& finalMonth, int& finalDay) {
	days += day;
	int monthID = month - 1;
	while (days > monthDay[monthID]) {
		days -= monthDay[monthID];
		monthID++;
	}
	finalMonth = monthID + 1; finalDay = days;
}

void print(int year, int month, int day) {
	if (year < 100) { 
		if (year < 10) { cout << "000" << year; }
		else { cout << "00" << year; }
	}
	else {
		if (year < 1000) { cout << "0" << year; }
		else { cout << year; }
	}

	if (month < 10) { cout << '0' << month; }
	else { cout << month; }

	if (day < 10) { cout << '0' << day; }
	else { cout << day; }
}