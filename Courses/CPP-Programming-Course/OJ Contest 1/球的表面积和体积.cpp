#include <iostream>
#include<iomanip>
using namespace std;
const double PI = 3.14;

int main() {
	int r;
	double s, v;
	cin >> r;
	s = 4 * PI * r * r;
	v = 4 * PI * r * r * r / 3;
	cout << fixed << setprecision(1) << s <<" "<< v << endl;
	return 0;
}

