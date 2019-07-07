#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);

    long long int two_x1 = 0;
    int sgn = 1;
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
        two_x1 += sgn * A[i];
        sgn *= -1;
    }

    cout << two_x1 << " ";

    long long int prev_x = two_x1 / 2;
    for (int i = 1; i < N; ++i) {
        const long long int cur_x = A[i - 1] - prev_x;
        cout << 2 * cur_x << " ";
        prev_x = cur_x;
    }
    cout << endl;

    return 0;
}
