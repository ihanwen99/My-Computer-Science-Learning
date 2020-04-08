#include <iostream>
using namespace std;

int main() {
	long long number;
	cin >> number;
	long long remainder=number*6%10;

	if (remainder==0) cout<<number*6/10<<endl;
	else cout<<number*6/10<<"."<<remainder<<endl;

	cout<<number*6/10<<" "<<remainder<<endl;
	return 0;
}