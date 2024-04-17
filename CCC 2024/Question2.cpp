#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    int T, N;
    vector<string> sequences;
    vector<char> output;
    int lastheavy;
    cin >> T >> N;
    cin.ignore();
    for (int i = 0; i < T; i++) {
        string line;
        getline(cin, line);
        sequences.push_back(line);
    }
    for (int i = 0; i < T; i++) {
        vector<int> heavy(26, 0);
        for (int j = 0; j < N; j++) {
            heavy[int(sequences[i][j]) - 97]++;
        }
        for (int j = 0; j < N; j++) {
            if (heavy[int(sequences[i][j]) - 97] > 1 && (lastheavy == 0 || j == 0)) {
                lastheavy = 1;
            }
            else if (heavy[int(sequences[i][j]) - 97] <= 1 && (lastheavy == 1 || j == 0)) {
                lastheavy = 0;
            }
            else {
                output.push_back('F');
                break;
            }
            if (j == N - 1) {
                output.push_back('T');
            }
        }
    }
    for (int i = 0; i < output.size(); i++) {
        cout << output[i] << "\n";
    }
}