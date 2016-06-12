#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<pair<int, int> > p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }

    sort(p.begin(), p.end(), greater<pair<int, int> >());
    pair<int, int> np = p[0];
    int ans = 1;
    for (size_t i = 1; i < n; ++i) {
        if (p[i].first < np.first && p[i].second < np.second) {
            np = p[i];
            ++ans;
        }
    }
    cout << ans << endl;

    return 0;
}
