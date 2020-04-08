#include<iostream>
using namespace std;

int main() {
	int n; cin >> n;
	int countMax = 0, count = 0, target;
	for (int i = 0; i < n; i++) {
		count = 0;
		for (int j = 0; j < n; j++) {
			cin >> target;
			if (target == 1) { count += 1; }
		}
		countMax = countMax >= count ? countMax : count;
	}

	cout << countMax << endl;

	return 0;
}