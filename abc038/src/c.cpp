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
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long int ans = 0;
    long long int chain = 0;

    for (size_t i = 0; i < n - 1; ++i) {
        if (a[i] < a[i + 1]) {
            ++chain;
        } else {
            ans += (chain * (chain + 1)) / 2;
            chain = 0;
        }
    }

    ans += (chain * (chain + 1)) / 2;
    ans += n;
    cout << ans << endl;

    return 0;
}
