#include<iostream>
using namespace std;

class Complex {
	int real;
	int viru;
public:
	Complex(int r = 0, int v = 0) :real(r), viru(v) {};
	void add(const Complex& a, const Complex& b);
	void display();
};

int main() {
	int ar, ai, br, bi, cr;
	cin >> ar >> ai >> br >> bi >> cr;

	Complex a(ar, ai), b(br, bi), c(cr), d;
	// a+b
	d.add(a, b);
	a.display();
	cout << " + ";
	b.display();
	cout << " = ";
	d.display();
	cout << endl;

	// a+c
	d.add(a, c);
	a.display();
	cout << " + ";
	c.display();
	cout << " = ";
	d.display();
	cout << endl;

	return 0;
}
void Complex::add(const Complex& a, const Complex& b) {
	this->real = a.real + b.real;
	this->viru = a.viru + b.viru;
}

void Complex::display() {
	bool realZero = (this->real == 0);
	bool viruZero = (this->viru == 0);

	cout << '(';
	if (realZero && viruZero) { cout << 0; }
	if (realZero && !viruZero) { cout << this->viru << 'i'; }
	if (viruZero && !realZero) { cout << this->real; }
	if (!realZero && !viruZero) {
		cout << this->real;
		if (this->viru < 0) { cout << this->viru; }
		else { cout << '+' << this->viru; }
		cout << 'i';
	}

	cout << ')';
}