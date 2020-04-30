#include<iostream>
using namespace std;

// Define your struct here. Its name *must* be my_complex.
struct my_complex {
	long long real;
	long long viru;
};
/**
 * Read a complex number.
 * @return pointer to the complex number just read, allocated on heap
 */
my_complex* read_complex() {
	my_complex* tmp = new my_complex;
	cin >> tmp->real >> tmp->viru;
	return tmp;
}

/**
 * Add two complex numbers.
 * @return pointer to the result, allocated on heap
 */
my_complex* add_complex(const my_complex* a, const my_complex* b) {
	my_complex* tmp = new my_complex;
	tmp->real = a->real + b->real;
	tmp->viru = a->viru + b->viru;
	return tmp;
}

/**
 * Print a complex number.
 */
void print_complex(const my_complex* a) {
	cout << a->real << '+' << a->viru << 'i';
}
