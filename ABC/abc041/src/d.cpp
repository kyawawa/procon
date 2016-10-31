#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 22:12
bool info(const vector<vector<int> > &rabbit, int x, int y)
{
    bool flag = true;
    for (int i = 0; i < rabbit[y-1].size(); i++) {
        if (rabbit[y-1][i] == x) return false;
        flag = info(rabbit, x, rabbit[y-1][i]);
    }
    return flag;
}

inline long long int fact(int x)
{
    long long int tmp = x;
    for (int i = 2; i < x; i++) {
        tmp *= i;
    }
    return tmp;
}

// 有益な情報の分/2していく
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > rabbit(n);
    vector<int> x(m), y(m);

    for (int i = 0; i < m; i++) {
        cin >> x[i] >> y[i];
        rabbit[y[i] - 1].push_back(x[i]);
    }

    int count = 0;
    for (int i = 0; i < m; i++) {
        if (!info(rabbit, x[i], y[i])) count++;
    }

    long long int ans = fact(n);
    for (int i = 0; i < count; i++) {
        ans /= 2;
    }

    cout << ans << endl;

    return 0;
}
