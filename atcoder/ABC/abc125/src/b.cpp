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

    int N;
    cin >> N;

    vector<int> price(N);
    int tmp_cost;
    int ans = 0;

    for (int i = 0; i < N; ++i) {
        cin >> price[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> tmp_cost;
        ans += max(price[i] - tmp_cost, 0);
    }

    cout << ans << endl;

    return 0;
}
