#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 10^9 < int < 10^10
// 再帰を回すと解ける? 時間は足らない

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    long C;
    cin >> N >> C;
    // vector<long> x(N);
    // vector<int> v(N);
    vector<pair<long, int>> sushi(N);
    for (int i = 0; i < N; ++i) {
        // cin >> x[i] >> v[i];
        cin >> sushi[i].first >> sushi[i].second;
    }

    sort(sushi.begin(), sushi.end());

    return 0;
}
