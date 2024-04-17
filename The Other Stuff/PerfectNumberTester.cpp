#include <iostream>
using namespace std;

int main() {
	int number;
	int sum = 0;
	cout << "Input number: ";
	cin >> number;
	for (int i = 1; i < number; i++) {
		if (number % i == 0) {
			sum += i;
		}
	}
	if (sum == number) {
		cout << "This is a perfect number. :)";
	}
	else {
		cout << "This is not a perfect number. :'(";
	}
}