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

    int N, D;
    cin >> N >> D;

    vector<vector<int>> X(N);
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        X[i].resize(D);
        for (int j = 0; j < D; ++j) cin >> X[i][j];

        for (int j = 0; j < i; ++j) {
            int squared_norm = 0;
            for (int k = 0; k < D; ++k) {
                squared_norm += (X[j][k] - X[i][k]) * (X[j][k] - X[i][k]);
            }

            double intpart;
            if (modf(sqrt(squared_norm), &intpart) == 0.0) ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
