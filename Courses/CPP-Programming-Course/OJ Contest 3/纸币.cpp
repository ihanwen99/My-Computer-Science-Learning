#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int money;
	cin >> money;
	int temp = money, count = 0;

	while (money >= 50) { money -= 50; count++; }
	while (money >= 20) { money -= 20; count++; }
	while (money >= 10) { money -= 10; count++; }
	while (money >= 5) { money -= 5; count++; }
	count += money;
	cout << count << ' ';

	money = temp;
	int v[] = { 1,5,16,23,33 };
	int* arr = new int[money + 1];
	for (int i = 0; i <= money + 1; i++) { arr[i] = i; }
	for (int j = 0; j <= 4 && money <= v[j]; j++) { arr[v[j]] = 1; }
	for (int i = 1; i <= money + 1; i++) {
		for (int j = 0; j <= 4; j++) {
			if (v[j] > i) { continue; }
			arr[i] = min(arr[i], arr[i - v[j]] + 1);
		}
	}
	cout << arr[money];

	return 0;
}
