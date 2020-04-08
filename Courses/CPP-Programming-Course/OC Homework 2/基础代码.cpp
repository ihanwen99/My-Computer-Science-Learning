#include <iostream>
#include<ctime>
#include <algorithm>
using namespace std;

int main() {
	srand(time(NULL));
	int m, n;
	cout << "请输入模拟的次数m: "; cin >> m;
	cout << "请输入每次模拟的步数n: "; cin >> n;

	long double total = 0;
	for (int i = 0; i < m; i++) {
		int x = 0, y = 0;
		for (int j = 0; j < n; j++) {
			int op = rand() * 4 / (RAND_MAX + 1);
			switch (op) {
			case 0:x++; y++;
			case 1:x++; y--;
			case 2:x--; y++;
			case 3:x--; y--;
			}
		}
		total += sqrt(pow(x, 2) + pow(y, 2));
	}
	cout << "对于模拟 " << m << " 次，每次 " << n << " 步的情况: 离出发位置 " << total / m << " m 远。" << endl;
	return 0;
}
