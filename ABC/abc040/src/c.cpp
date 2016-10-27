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
    vector<int> costs(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    costs[0] = 0;
    costs[1] = abs(a[1] - a[0]);

    for (int i = 2; i < n; ++i) {
        costs[i] = min((costs[i-2] + abs(a[i] - a[i-2])), (costs[i-1] + abs(a[i] - a[i-1])));
    }
    cout << costs[n-1] << endl;
    return 0;
}
