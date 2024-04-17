#include <iostream>
#include <cmath>
using namespace std;

int LucasLehmer(long long int p) {
	long long int s = 4;
	long long int M = (1LL << p) - 1;
	for (int i = 0; i < p - 2; i++) {
		s = ((s * s) - 2) % M;
	}
	if (s == 0) {
		return 0;
	}
	else {
		return 1;
	}
}


int main() {
	long long int  prime;
	cout << "Prime: ";
	cin >> prime;
	if (LucasLehmer(prime) == 0) {
		cout << "2^" << prime << "-1 is a prime number :). Its respective perfect number is " << (1LL << (prime - 1)) * ((1LL << prime) - 1);
	}
	else {
		cout << "2^" << prime << "-1 is not a prime number :(";
	}
}