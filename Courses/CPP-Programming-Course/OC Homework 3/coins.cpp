#include<iostream>
#include<ctime>
using namespace std;

int main() {
	int times[11] = { 0 };
	int n;

	srand(time(NULL));
	cout << "请输入您想测试的次数(建议较大数值): "; cin >> n;
	for (int i = 0; i < n; i++) {
		int sum = 0, num = 0;
		for (int j = 0; j < 10; j++) {
			num = rand() * 100 / (RAND_MAX + 1) + 1;
			if (num <= 50) { sum += 10; }
			else { sum += 5; }
		}
		times[sum / 5 - 10]++;
	}
	cout << "下面是从 50 到 100 的 11 个值: " << endl;
	for (int i = 0; i < 11; i++) {
		cout << times[i] << ' ';
	}
	return 0;
}