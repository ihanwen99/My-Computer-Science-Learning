#include <iostream>
using namespace std;

int main() {
	int month, day, year;
	cin >> month >> day >> year;

	// Judge Validation
	// Step1: Leap year
	bool leap_year_flag = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

	bool validation_flag;
	// Step2: Month Validation
	validation_flag = (month <= 12);
	if (!validation_flag) { cout << 0; return 0; }

	// Step3: Date-Month Validation 
	if (month == 1 or month == 3 or month == 5 or month == 7 or month == 8 or month == 10 or month == 12) {
		validation_flag = (day <= 31);
	}
	else if (month == 4 or month == 6 or month == 9 or month == 11) {
		validation_flag = (day <= 30);
	}
	else {
		validation_flag = (day <= 28 + leap_year_flag);
	}	
	if (!validation_flag) { cout << 0; return 0; }

	// Calculation 
	int dayNum;
	switch (month) {
	case 1:dayNum = day; break;
	case 2:dayNum = 31 + day; break;
	default:dayNum = 31 * (month - 1) + day - (4 * month + 23) / 10 + leap_year_flag;
	}
	cout << dayNum << endl;

	return 0;
}