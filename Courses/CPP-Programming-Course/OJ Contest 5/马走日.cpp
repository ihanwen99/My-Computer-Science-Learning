#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class node {
public:
	int x;
	int y;

	node(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool backTracking(int** arr, int x, int y, int step);
bool compare(node n1, node n2);
int nextStepCountFunc(int x, int y);
int distanceFromCenterFunc(int x, int y);
vector< node > generateNextStep(int x, int y);

int mv_x[] = { 1,2,2,1,-1,-2,-2,-1 };
int mv_y[] = { 2,1,-1,-2,-2,-1,1,2 };
int n;
int** arr;



int main() {
	cin >> n;
	int x, y; cin >> x >> y;

	arr = new int* [n];
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
	if (step == n * n) { return true; }

	vector< node > neighbours = generateNextStep(x, y);
	sort(neighbours.begin(), neighbours.end(), compare);

	for (auto e : neighbours) {
		int new_x = e.x, new_y = e.y;
		bool temp = backTracking(arr, new_x, new_y, step + 1);
		if (temp)return true;
	}

	arr[x][y] = 0;
	return false;
}


bool compare(node n1, node n2) {
	int nextStepCount1 = nextStepCountFunc(n1.x, n1.y), nextStepCount2 = nextStepCountFunc(n2.x, n2.y);
	int distanceFromCenter1 = distanceFromCenterFunc(n1.x, n1.y), distanceFromCenter2 = distanceFromCenterFunc(n2.x, n2.y);
	if (nextStepCount1 != nextStepCount2) { return nextStepCount1 < nextStepCount2; }
	else { return distanceFromCenter1 > distanceFromCenter2; }
}


int nextStepCountFunc(int x, int y) {
	return generateNextStep(x, y).size();
}

int distanceFromCenterFunc(int x, int y) {
	return (int)(pow(x - n / 2, 2) + pow(y - n / 2, 2));
}

vector< node > generateNextStep(int x, int y) {
	vector< node > neighbours;
	for (int i = 0; i < 8; i++) {
		int new_x = x + mv_x[i], new_y = y + mv_y[i];
		if (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n && arr[new_x][new_y] == 0) {
			neighbours.push_back(node(new_x, new_y));
		}
	}
	return neighbours;
}