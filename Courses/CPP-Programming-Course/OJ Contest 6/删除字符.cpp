#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
	int n; cin >> n;
	string* arr = new string[n];
	string temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		arr[i] = temp;
	}

	char target; cin >> target;

	for (int i = 0; i < n; i++) {
		temp = arr[i];
		temp.erase(remove(temp.begin(), temp.end(), target), temp.end());
		arr[i] = temp;
	}

	sort(arr, arr + n);
	for (int i = n-1; i >=0; i--) {
		cout << arr[i] << endl;;
	}
	return 0;
}