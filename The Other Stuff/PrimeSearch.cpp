#include <iostream>
#include <vector>
using namespace std;

int main() {
	int max;
	int factors = 0;
	int die = 0;
	vector<int> primes;
	cout << "Max: ";
	cin >> max;
	for (int i = 1; i <= max; i++) {
		for (int j = 1; j <= i; j++) {
			if (i % j == 0) {
				factors++;
				if (factors == 2 && i != j) {
					die = 1;
					break;
				}
			}
		}
		if (factors == 2 && die == 0) {
			primes.push_back(i);
		}
		factors = 0;
		die = 0;
	}
	for (int i = 0; i < primes.size(); i++) {
		cout << primes[i] << "\n";
	}
}