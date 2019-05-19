#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 何回連続で表を出さなければいけないのかはKをn回2で割った数を切り上げた数との比較で分かる
// 計算量が O(logK) で結構速いはず

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    double ans = 0;
    int n_right = N;
    int i = 0;
    for (int num = K; n_right > 0; num = (num + 1) / 2, ++i) {
        if (n_right - num < 0) continue;
        ans += (n_right - num + 1) * pow(0.5, i);
        n_right = num - 1;
    }

    cout << setprecision(10) << ans / N << endl;

    return 0;
}
