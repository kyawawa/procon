#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
using ull = unsigned long long;

// 一番ボトルネックの移動に必要な回数に4を足すだけ(結局他は合計回数に影響しない)

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    ull N;
    ull trans;

    cin >> N;
    ull min_trans = N;
    for (int i = 0; i < 5; ++i) {
        cin >> trans;
        min_trans = min(trans, min_trans);
    }
    cout << static_cast<ull>(ceil(N / (double)min_trans)) + 4 << endl;
    return 0;
}
