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

    int N, K;
    cin >> N >> K;

    long long int ans = 0;
    int start = 0;

    if (K % 2 == 0) start = K / 2;
    else start = K;
    if (start > N) {
        cout << 0 << endl;
        return 0;
    }
    ++ans;

    int num_K = (N - start) / K;
    ans += pow((num_K + 1), 3) - 1;

    if (K % 2 == 0) {
        ans *= 2;
        if ((N - start) % K < K / 2) {
            ans -= (pow((num_K + 1), 2) * 3 - (num_K + 1) * 3 + 1);
        }
    }

    cout << ans << endl;

    return 0;
}
