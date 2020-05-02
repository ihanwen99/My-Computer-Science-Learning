#include "management.h"

void outputStudent(student s) {
	cout << setw(4) << s.id << setw(16) << s.name << setw(4) << s.chiScore << setw(4) << s.mathScore << setw(4) << s.engScore << endl;
}

bool compareID(const student& a, const student& b) {
	return a.id < b.id;
}

void outputID() {
	int length = studentList.size();
	sort(studentList.begin(), studentList.end(), compareID);
	for (int i = 0; i < length; i++) {
		outputStudent(studentList[i]);
	}
}

bool compareSys(const student& a, const student& b) {
	if (a.totalScore != b.totalScore) {
		return a.totalScore > b.totalScore;
	}
	else {
		return a.id < b.id;
	}
}

void outputSys() {
	int length = studentList.size();
	sort(studentList.begin(), studentList.end(), compareSys);
	for (int i = 0; i < length; i++) {
		outputStudent(studentList[i]);
	}

}