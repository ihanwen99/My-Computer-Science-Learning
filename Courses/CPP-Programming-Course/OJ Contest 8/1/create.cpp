#include "management.h"

void add() {
	int id, chiScore, mathScore, engScore;
	string name;
	cin >> id >> name >> chiScore >> mathScore >> engScore;
	int length = studentList.size(), idx;
	for (idx = 0; idx < length; idx++) {
		if (studentList[idx].id == id) {
			cout << "Duplicate detected." << endl;
			break;
		}
	}
	if (idx == length) {
		student tmp(id, name, chiScore, mathScore, engScore);
		studentList.push_back(tmp);
	}
}