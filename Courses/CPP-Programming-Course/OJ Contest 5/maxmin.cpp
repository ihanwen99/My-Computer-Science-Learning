// Define your maxmin template function here, which has two parameters
// 1. a: the array
// 2. int size: the size of the array

template<class T>
T maxmin(T a[], int length) {
	T maxT = a[0], minT = a[0];
	for (int i = 0; i < length; i++) {
		if (a[i] > maxT) { maxT = a[i]; }
		if (a[i] < minT) { minT = a[i]; }
	}
	cout << maxT << ' ' << minT;
}