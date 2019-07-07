#include <iostream>
#include <iomanip>
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

    int L, R;
    cin >> L >> R;

    int l_mod = L % 2019;
    int r_mod = R % 2019;

    int ans = 2019;
    if (R - L > 2019 || r_mod <= l_mod) ans = 0;
    else {

    }

    cout << ans << endl;
    return 0;
}
