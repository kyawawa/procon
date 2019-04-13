#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int X, Y, Z, K;
    vector<ull> A(X);
    vector<ull> B(Y);
    vector<ull> C(Z);

    for (int i = 0; i < X; ++i) cin >> A[i];
    for (int i = 0; i < Y; ++i) cin >> B[i];
    for (int i = 0; i < Z; ++i) cin >> C[i];

    sort(A.begin(), A.end(), greater<ull>);
    sort(B.begin(), B.end(), greater<ull>);
    sort(C.begin(), C.end(), greater<ull>);

    vector<vector<vector<ull>>> ABC(X);

    return 0;
}
