#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int N;
    int line;
    string output1;
    int swipes;
    int counter1 = 0;
    int counter2 = 0;
    vector<int> A;
    vector<int> B;
    cin >> N;
    vector<int> matching(300000, 0);
    for (int i = 0; i < N; i++) {
        cin >> line;
        A.push_back(line);
    }
    for (int i = 0; i < N; i++) {
        cin >> line;
        B.push_back(line);
    }
    for (int i = 0; i < N; i++) {
        if (matching[A[i] - 1] == 1) {
            continue;
        }
        else {
            matching[A[i] - 1]++;
        }
    }
    for (int i = 0; i < N; i++) {
        if (matching[B[i] - 1] == 0) {
            cout << "NO";
            return 0;
        }
    }
    if (A == B) {
        cout << "YES";
        return 0;
    }
    for (int i = 0; i < N; i++) {
        if ((A[i] == B[i + 1] || A[i] == B[i - 1]) && B[i] == A[i]) {
            counter2++;
        }
        else {
            counter1++;
        }
    }
    if (counter2 > 0) {
        cout << "YES";
    }
    else {
        cout << "NO";
    }
}