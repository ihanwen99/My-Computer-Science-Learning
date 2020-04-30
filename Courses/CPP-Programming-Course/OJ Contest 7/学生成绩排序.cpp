#include<iostream>
#include<cstring>
using namespace std;


struct student {
	string name;
	int chiScore;
	int mathScore;
	int engScore;
};

bool compare(student a, student b) {
	int totalA = a.chiScore + a.mathScore + a.engScore;
	int totalB = b.chiScore + b.mathScore + b.engScore;
	if (totalA > totalB) { return true; }
	if (totalA < totalB) { return false; }
	//totalA==totalB
	if (a.chiScore > b.chiScore) { return true; }
	if (a.chiScore < b.chiScore) { return false; }
	//a.chiScore==b.chiScore
	if (a.mathScore > b.mathScore) { return true; }
	if (a.mathScore < b.mathScore) { return false; }
	//a.mathScore==b.mathScore
	if (a.engScore > b.engScore) { return true; }
	if (a.engScore < b.engScore) { return false; }
	//a.engScore==b.engScore
	return a.name < b.name;

}
int main() {
	int times; cin >> times;
	student* arr = new student[times];
	for (int i = 0; i < times; i++) {
		cin >> arr[i].name >> arr[i].chiScore >> arr[i].mathScore >> arr[i].engScore;
	}
	//sort
	for (int i = 0; i < times - 1; i++) {
		bool flag = true;
		for (int j = 0; j < times - i - 1; j++) {
			if (!compare(arr[j], arr[j + 1])) {
				student tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = false;
			}
		}
		if (flag) { break; }
	}
	/*for (int choose = 1; choose <= times; choose++) {
		cout << arr[choose - 1].name << ' ' << arr[choose - 1].chiScore + arr[choose - 1].mathScore + arr[choose - 1].engScore;
	}*/
	int choose; cin >> choose;
	cout << arr[choose - 1].name <<' '<< arr[choose - 1].chiScore + arr[choose - 1].mathScore + arr[choose - 1].engScore;
}