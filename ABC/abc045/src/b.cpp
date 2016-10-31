#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    string A, B, C;
    cin >> A;
    cin >> B;
    cin >> C;
    char turn = 'a';
    int a = 0, b = 0, c = 0;

    while (true) {
        if (turn == 'a') {
            if (a == A.length()) {
                cout << "A" << endl;
                break;
            } else {
                turn = A[a++];
            }
        } else if (turn == 'b') {
            if (b == B.length()) {
                cout << "B" << endl;
                break;
            } else {
                turn = B[b++];
            }
        } else if (turn == 'c') {
            if (c == C.length()) {
                cout << "C" << endl;
                break;
            } else {
                turn = C[c++];
            }
        }
    }
    return 0;
}
