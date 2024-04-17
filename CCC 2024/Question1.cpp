#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    vector<int> hats;
    int output = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int h;
        cin >> h;
        hats.push_back(h);
    }
    for (int i = 0; i < N; i++) {
        if (hats[i] == hats[(i + N/2) % N]) {
            output++;
        }
    }
    cout << output;

}