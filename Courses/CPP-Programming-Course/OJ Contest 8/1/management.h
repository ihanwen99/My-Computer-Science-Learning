#ifndef MANAGEMENT_H
#define MANAGEMENT_H

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

extern vector<student> studentList;
#endif