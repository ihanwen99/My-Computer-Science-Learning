#include<iostream>
#include <iomanip>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;

class student {
public:
	int id;
	string name;
	int chiScore;
	int mathScore;
	int engScore;
	int totalScore;
	student(int id, string name, int chiScore, int mathScore, int engScore) {
		this->id = id;
		this->name = name;
		this->chiScore = chiScore;
		this->mathScore = mathScore;
		this->engScore = engScore;
		this->totalScore = chiScore + mathScore + engScore;
	}
};

void add();
void change();
void queryByID();
void queryByName();
void outputStudent(student);
void outputID();
void outputSys();
bool compareID(const student& a, const student& b);
bool compareSys(const student& a, const student& b);

vector<student> studentList;

int main() {
	int n; cin >> n;
	int operation;
	void(*func[7])() = { NULL,add,change,queryByID,queryByName,outputID,outputSys };
	for (int i = 0; i < n; ++i) {
		cin >> operation;
		func[operation]();
	}
	return 0;
}

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