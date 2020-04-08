#include <iostream>
using namespace std;

int main() {
	int time;
	cin >> time;
	int hour = 0, minute = 0, second = 0;

	second = time % 60;
	time /= 60;
	minute = time % 60;
	hour = time / 60;
	cout << hour << ":" << minute << ":" << second << endl;
	return 0;
}