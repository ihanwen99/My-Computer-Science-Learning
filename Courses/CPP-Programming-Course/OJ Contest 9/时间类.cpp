#include<iostream>
using namespace std;

class Time {
	int h, m, s;
public:
	Time(int hh, int mm, int ss) :h(hh), m(mm), s(ss) {};
	void settime(int hh, int mm, int ss) { this->h = hh; this->m = mm; this->s = ss; }
	void display();
	void add(int seconds);
};

int main()
{
	int h1, m1, s1, h2, m2, s2, addseconds1, addseconds2;
	cin >> h1 >> m1 >> s1;
	cin >> addseconds1;
	cin >> h2 >> m2 >> s2;
	cin >> addseconds2;
	Time t(h1, m1, s1);
	t.display();
	t.add(addseconds1);
	t.display();
	t.settime(h2, m2, s2);
	t.display();
	t.add(addseconds2);
	t.display();

	return 0;
}


void Time::add(int seconds) {
	int tmp, extra;

	tmp = this->s + seconds;
	extra = tmp / 60;
	this->s = tmp % 60;

	tmp = this->m + extra;
	extra = tmp / 60;
	this->m = tmp % 60;

	tmp = this->h + extra;
	this->h = tmp % 24;
}

void Time::display() {
	cout.fill('0');
	cout.width(2); cout << this->h << ':';
	cout.width(2); cout << this->m << ':';
	cout.width(2); cout << this->s << endl;
}