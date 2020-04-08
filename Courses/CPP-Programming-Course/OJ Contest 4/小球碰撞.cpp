#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int N, L; cin >> N >> L;
	bool right = true;

	int target;
	// leftMin: Direction is left && Coordinate is minimum.
	int leftMin = L, rightMin = L, leftMax = 0, rightMax = 0;
	for (int i = 0; i < N; i++) {
		cin >> target;
		if (right) { rightMin = min(rightMin, target); rightMax = max(rightMax, target); }
		else { leftMin = min(leftMin, target); leftMax = max(leftMax, target); }
		right = right ? false : true;
	}

	// minTime -> 向左最靠左 PK 向右最靠右
	int minTime = min(leftMin, L - rightMax);
	// maxTime -> 向左最靠右 PK 向右最靠左
	int maxTime = max(leftMax, L-rightMin);

	cout << minTime << ' ' << maxTime << endl;

	return 0;
}