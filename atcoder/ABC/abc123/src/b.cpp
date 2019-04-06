#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 切り上げが一番大きい料理を最後に選ぶだけ

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int dish;
    int ans = 0;
    int last_rest = 0;
    for (int i = 0; i < 5; ++i) {
        cin >> dish;
        int dish_round_up = ((dish + 9) / 10) * 10;
        ans += dish_round_up;
        last_rest = max(last_rest, dish_round_up - dish);
    }
    cout << ans - last_rest << endl;
    return 0;
}
