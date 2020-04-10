#include<iostream>
using namespace std;

bool check(int x, int y);
bool backTracking(int** arr, int x, int y, int step);

int mv_x[] = { 1,2,2,1,-1,-2,-2,-1 };
int mv_y[] = { 2,1,-1,-2,-2,-1,1,2 };
int n;


int main() {
	cin >> n;
	int x, y; cin >> x >> y;

	int** arr = new int* [n];
	for (int i = 0; i < n; i++) { arr[i] = new int[n] { 0 }; }

	bool flag = false;
	flag = backTracking(arr, x - 1, y - 1, 1);

	if (flag) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << ' ';
			}
			cout << endl;
		}
	}
	else { cout << "None"; }

	for (int i = 0; i < n; i++) { delete[]arr[i]; }
	delete[]arr;
}



bool backTracking(int** arr, int x, int y, int step) {
	arr[x][y] = step;
	if (step == n * n) {return true;}

	for (int i = 0; i < 8; i++) {
		int new_x = x + mv_x[i], new_y = y + mv_y[i];

		if ((new_x >= 0 && new_y >= 0 && new_x < n && new_y < n) && arr[new_x][new_y] == 0) {
			bool temp = backTracking(arr, new_x, new_y, step + 1);
			if (temp)return true;
		}
	}
	arr[x][y] = 0;
	return false;
}