#include<iostream>
using namespace std;

int main() {
	int R, C; cin >> R >> C;
	int** arr = new int* [R];
	for (int i = 0; i < R; i++) {
		arr[i] = new int[C];
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> arr[i][j];
		}
	}

	int* rowMaxID = new int[R];
	int* colMinID = new int[C];
	for (int i = 0; i < R; i++) {
		int target = arr[i][0], idx = 0;
		for (int j = 0; j < C; j++) {
			if (arr[i][j] > target) {
				target = arr[i][j];
				idx = j;
			}
		}
		rowMaxID[i] = idx;
	}

	for (int j = 0; j < C; j++) {
		int target = arr[0][j], idx = 0;
		for (int i = 0; i < R; i++) {
			if (arr[i][j] < target) {
				target = arr[i][j];
				idx = i;
			}
		}
		colMinID[j] = idx;
	}

	bool flag = false;
	for (int i = 0; i < R; i++) {
		int idx = rowMaxID[i];
		int target = arr[i][idx];
		for (int j = idx; j < C; j++) {
			if (arr[i][j] == target && i==colMinID[j]) {
				flag = true;
				cout << i + 1 << ' ' << j + 1 << endl;
			}
		}
	}

	if (flag == false) { cout << "NONE"; }


	return 0;
}