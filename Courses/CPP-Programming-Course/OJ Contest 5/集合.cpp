#include<iostream>
#include<algorithm>
using namespace std;

int set_process(int arr[], int n) {
	int* temp = new int[n];
	int length = 0;

	for (int i = 0; i < n; i++) {
		int j = i + 1;
		for (; j < n; j++) {
			if (arr[j] == arr[i]) { break; }
		}
		if (j == n) {
			temp[length++] = arr[i];
		}
	}
	for (int i = 0; i < length; i++) { arr[i] = temp[i]; }
	delete[] temp;
	return length;
}

void Add(int set[], int n, int num) {
	/* Add num into set, then print the set.*/
	int length = set_process(set, n);
	int i = 0;
	for (; i < length; i++) {
		if (set[i] == num) {
			break;
		}
	}
	if (i == length) {
		set[length++] = num;
	}

	sort(set, set + length);
	for (int i = 0; i < length; i++) {
		cout << set[i] << (i == length - 1 ? '\n' : ' ');
	}
}

void Find(int set[], int n, int num) {
	/* Find num in set, if found, print 1, else print 0.*/
	int length = set_process(set, n);
	int i = 0;
	for (; i < length; i++) {
		if (set[i] == num) {
			break;
		}
	}
	cout << (i == length ? 0 : 1);
}

void Intersection(int set1[], int n, int set2[], int m) {
	/* Get the intersection of set1 and set2, then print the result.*/
	int length1 = set_process(set1, n);
	int length2 = set_process(set2, m);

	sort(set1, set1 + length1);
	sort(set2, set2 + length2);

	int num;
	bool flag = false;
	for (int i = 0; i < length1; i++) {
		num = set1[i];
		for (int j = 0; j < length2; j++) {
			if (num == set2[j]) {
				cout << num << ' ';
				flag = true;
				break;
			}
		}
	}
	if (!flag) { cout << "NoOutput" << endl; }
}

void Union(int set1[], int n, int set2[], int m) {
	/* Get the union of set1 and set2, then print the result.*/
	int length1 = set_process(set1, n);
	int length2 = set_process(set2, m);

	int* temp = new int[length1 + length2];
	for (int i = 0; i < length1; i++) { temp[i] = set1[i]; }
	for (int i = 0; i < length2; i++) { temp[i + length1] = set2[i]; }
	int length = set_process(temp, length1 + length2);

	sort(temp, temp + length);
	for (int i = 0; i < length; i++) { cout << temp[i] << (i == length - 1 ? '\n' : ' '); }
	delete[] temp;
}
