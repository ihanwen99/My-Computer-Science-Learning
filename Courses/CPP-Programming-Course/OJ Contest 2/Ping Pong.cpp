#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;

	// Under 11 -> Unknown
	if (max(a, b) < 11) { cout << "Unknown"; return 0; }

	// One is 11, the other is less than 10 -> Win 
	if (max(a, b) == 11 && min(a, b) < 10) {
		cout << ((a == 11) ? "A" : "B") << " win"; return 0;
	}

	// One is greater than 11, the other is less than 10 -> Illegal
	if (max(a, b) > 11 && min(a, b) < 10) {
		cout << "Illegal"; return 0;
	}

	// Both >= 10
	if (min(a, b) >= 10) {
		if (abs(a - b) == 2) {
			cout << ((a > b) ? "A" : "B") << " win"; return 0;
		}
		else if (abs(a - b) < 2) { cout << "Unknown"; return 0; }
		else { cout << "Illegal"; return 0; }
	}

	return 0;
}