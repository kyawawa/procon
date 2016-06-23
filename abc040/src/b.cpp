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

    int n;
    cin >> n;
    int a = sqrt(n);
    int ans = n - a * a;
    int b, tmp_ans;

    for (int i = a; i > 0 && ((b = n / i) - i) < ans; --i) {
        tmp_ans = (n - b * i) + (b - i);
        if (tmp_ans < ans) ans = tmp_ans;
    }

    cout << ans << endl;

    return 0;
}
