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

    int N, X;
    cin >> N >> X;

    vector<int> m(N);
    int sum = 0;
    int min = 10000;

    for (int i = 0; i < N; ++i) {
        cin >> m[i];
        sum += m[i];
        if (m[i] < min) min = m[i];
    }

    cout << N + (X - sum) / min << endl;

    return 0;
}
