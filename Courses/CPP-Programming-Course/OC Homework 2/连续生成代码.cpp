#include <iostream>
#include<ctime>
#include <algorithm>
using namespace std;

int main() {
	srand(time(NULL));
	int m = 10000;
//	int arr[] = { 1,10,100,1000,10000,100000,1000000 };

//	for (int k = 0; k < sizeof(arr) / sizeof(*arr); k++) {
	for (int k = 0; k < 500; k++) {
		int currValue = k + 1;
		long double total = 0;
		for (int i = 0; i < m; i++) {
			int x = 0, y = 0;
			for (int j = 0; j < currValue; j++) {
				int op = rand() * 4 / (RAND_MAX + 1);
				switch (op) {
				case 0:x++; break;
				case 1:x--; break;
				case 2:y++; break;
				case 3:y--; break;
				}
			}
			total += sqrt(pow(x, 2) + pow(y, 2));
		}
		cout << total / m << endl;
	}

	return 0;
}