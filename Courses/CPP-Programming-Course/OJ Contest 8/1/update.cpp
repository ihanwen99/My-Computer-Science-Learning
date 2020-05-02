#include "management.h"

void change() {
	int targetID, idx; cin >> targetID;
	int length = studentList.size();
	bool find = false;
	for (idx = 0; idx < length; idx++) {
		if (studentList[idx].id == targetID) { find = true; break; }
	}
	if (find) {
		student& tmp = studentList[idx];

		string operation; cin >> operation;
		if (operation == "N") { string newName; cin >> newName; tmp.name = newName; }
		else {
			int input; cin >> input;
			if (operation == "ID") { tmp.id = input; }
			if (operation == "C") { tmp.chiScore = input; tmp.totalScore = tmp.chiScore + tmp.mathScore + tmp.engScore; }
			if (operation == "M") { tmp.mathScore = input; tmp.totalScore = tmp.chiScore + tmp.mathScore + tmp.engScore; }
			if (operation == "E") { tmp.engScore = input; tmp.totalScore = tmp.chiScore + tmp.mathScore + tmp.engScore; }
		}
	}
	else {
		string useless1, useless2; cin >> useless1 >> useless2;
		cout << "Not found." << endl;
	}
}