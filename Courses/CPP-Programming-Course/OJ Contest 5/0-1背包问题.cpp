#include <iostream>
#include <algorithm> 
using namespace std;

int knapsack(int n, int s[], int v[], int C);

int main() {
	int n, c; cin >> n >> c;
	int* s = new int[n]; for (int i = 0; i < n; i++) { cin >> s[i]; }
	int* v = new int[n]; for (int i = 0; i < n; i++) { cin >> v[i]; }
	cout << knapsack(n, s, v, c);

	return 0;
}

int knapsack(int n, int s[], int v[], int C) {
	int** arr = new int* [n + 1];
	for (int i = 0; i < n + 1; i++) { arr[i] = new int[C + 1]; }

	for (int i = 0; i < n + 1; i++) { arr[i][0] = 0; }
	for (int i = 0; i < C + 1; i++) { arr[0][i] = 0; }

	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < C + 1; j++) {
			if (s[i - 1] > j) { arr[i][j] = arr[i - 1][j]; }
			else { arr[i][j] = max(arr[i - 1][j], arr[i - 1][j - s[i - 1]] + v[i - 1]); }
		}
	}

	int result = arr[n][C];

	for (int i = 0; i < n + 1; i++) { delete[] arr[i]; }
	delete[]arr;

	return result;
}
