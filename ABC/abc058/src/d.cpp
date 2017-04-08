#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int minus_to_zero(int x) {
    return x <= 0 ? 0 : x;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<long long int> x(n);
    vector<long long int> y(m);
    for (int i = 0; i < n; ++i) cin >> x[i];
    for (int i = 0; i < m; ++i) cin >> y[i];
    vector<vector<long long int> > rect(n-1);
    vector<vector<long> > rect_num(n-1);
    for (int i = 0; i < n-1; ++i) {
        rect[i].resize(m-1);
        rect_num[i].resize(m-1, 0);
        for (int j = 0; j < m-1; ++j) {
            rect[i][j] = (x[i+1] - x[i]) * (y[j+1] - y[j]);
        }
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 1; j < m; ++j) {
            for (int a = 0; a < n-1; ++a) {
                for (int b = 0; b < m-1; ++b) {
                    rect_num[a][b] += (i - minus_to_zero((i - min(a, n-2-a) - 1))) * (j - minus_to_zero((j - min(b, m-2-b) - 1)));
                }
            }
        }
    }
    long long int ans = 0;
    for (int a = 0; a < n-1; ++a) {
        for (int b = 0; b < m-1; ++b) {
            ans += (rect[a][b] * rect_num[a][b]) % (1000000000 + 7);
        }
    }
    cout << ans % (1000000000 + 7) << endl;
    return 0;
}
