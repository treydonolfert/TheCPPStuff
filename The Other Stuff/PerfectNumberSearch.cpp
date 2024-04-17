#include <iostream>
#include <vector>
using namespace std;

int main() {
	int maxnumber;
	vector<int> perfectnumbers;
	int sum;
	cout << "Input number: ";
	cin >> maxnumber;
	for (int i = 1; i < maxnumber; i++) {
		sum = 0;
		for (int j = 1; j < i; j++) {
			if (i % j == 0) {
				sum += j;
			}
		}
		if (sum == i) {
			perfectnumbers.push_back(i);
		}
	}
	cout << "Perfect numbers: \n";
	for (int i = 0; i < perfectnumbers.size(); i++) {
		cout << perfectnumbers[i] << "\n";
	}
	
}