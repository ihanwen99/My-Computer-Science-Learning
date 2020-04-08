#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (b > 2592) { b = 2592; } 
	//为了加速，发现4位数的最大可能是 4 * 9 * 9 * 9
	// 但是事实上，一共也没有几个伪阿姆斯特朗数，都可以定制化输出
	// 0 1 153 370 371 407

	bool flag = false;
	for (int i = a; i <= b; i++) {
		int temp = i, value = 0, res;
		while (temp > 0) {
			res = temp % 10;
			value += pow(res, 3);
			temp /= 10;
		}
		if (value == i) { flag = true; cout << i << ' '; }
	}
	if (!flag) { cout << "NONE" << endl; }

	return 0;
}
