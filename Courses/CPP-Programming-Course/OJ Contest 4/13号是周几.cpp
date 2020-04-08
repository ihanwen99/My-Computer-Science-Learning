#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;

	int result[7] = { 0 };
	//事实上只初始化了第一个元素，剩下的元素因为没有传入值，默认初始化为0
	int month[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	int base = 6;
	//前一年最后一天的情况作为基准，映射到 0-6

	for (int year = 1900; year <= 1900 + n - 1; year++) {
		bool isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
		for (int month = 1; month <= 12; month++) {
			//dayNum 每个月13号在当前年份的天数
			int dayNum;
			switch (month) {
			case 1:dayNum = 13; break;
			case 2:dayNum = 31 + 13; break;
			default:dayNum = 31 * (month - 1) + 13 - (4 * month + 23) / 10 + isLeapYear;
			}
			result[(dayNum + base) % 7]++;
		}
		base = (365 + isLeapYear + base) % 7;
	}

	for (int i = 0; i < 7; i++) {
		cout << result[i] << ' ';
	}
	return 0;
}
