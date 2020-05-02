#include "management.h"

void queryByID() {
	int targetID; cin >> targetID;
	bool find = false;
	int length = studentList.size();
	for (int idx = 0; idx < length; idx++) {
		if (studentList[idx].id == targetID) { find = true; outputStudent(studentList[idx]); }
	}
	if (!find) { cout << "Not found." << endl; }
}

void queryByName() {
	string targetName; cin >> targetName;
	int length = studentList.size();
	vector<student>newStudentList;
	for (int idx = 0; idx < length; idx++) {
		if (studentList[idx].name == targetName) { newStudentList.push_back(studentList[idx]); }
	}
	length = newStudentList.size();
	if (length > 0) {
		sort(newStudentList.begin(), newStudentList.end(), compareID);
		for (int i = 0; i < length; i++) { outputStudent(newStudentList[i]); }
	}
	else { cout << "Not found." << endl; }
}