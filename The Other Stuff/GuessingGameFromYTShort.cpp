#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int previously(int num, vector<int> init) {
	for (int i = 0; i < init.size(); i++) {
		if (num == init[i]) {
			return 1;
		}
	}
	return 0;
}

int compare(vector<int> input, vector<int> numbs) {
	int counter = 0;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == numbs[i]) {
			counter++;
		}
	}
	return counter;
}

int main() {
	srand(time(NULL));
	vector<int> numbers;
	vector<int> initial(5,-1);
	vector<int> playersNumbers;
	int random = 0;
	for (int i = 0; i < 5; i++) {
		random = 0;
		while (previously(random, initial) == 1 || random == 0) {
			random = 1 + rand() % 5;
		}
		initial[i] = random;
		numbers.push_back(random);
	}
	cout << "Make your first guess: ";
	string line;
	getline(cin, line);
	stringstream ss(line);
	int temp;
	while (ss >> temp) {
		playersNumbers.push_back(temp);
	}
	cout << compare(playersNumbers, numbers) << " correct. Try again: ";
	for (int i = 0; i < numbers.size(); i++) {
		cout << numbers[i] << "\n";
	}
	for (int i = 0; i < playersNumbers.size(); i++) {
		cout << playersNumbers[i] << "\n";
	}
}