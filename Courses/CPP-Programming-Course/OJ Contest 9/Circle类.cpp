#include<iostream>
using namespace std;

class Circle {
	int x;
	int y;
	int r;
public:
	Circle(int xx, int yy, int rr) :x(xx), y(yy), r(rr) {};
	void getO(int& cx, int& cy) { cx = this->x; cy = this->y; }
	int getR() { return this->r; }
	void move(int mx, int my) { this->x += mx; this->y += my; }
	void setR(int rr) { this->r = rr; }
};

int main() {
	int x, y, r;
	cin >> x >> y >> r;
	Circle c(x, y, r);

	int cx, cy;
	c.getO(cx, cy);
	cout << cx << ' ' << cy << endl;
	cout << c.getR() << endl;

	int move_x, move_y;
	cin >> move_x >> move_y;
	c.move(move_x, move_y);
	c.getO(cx, cy);
	cout << cx << ' ' << cy << endl;

	int new_r;
	cin >> new_r;
	c.setR(new_r);
	cout << c.getR() << endl;

	return 0;
}