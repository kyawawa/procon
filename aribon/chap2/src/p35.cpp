// POJ No.2386
#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void search(vector<string>& s, int y, int x)
{
    s[y][x] = '.';
    for (int i = -1; i < 2; ++i) {
        for (int j = -1; j < 2; ++j) {
            if (s[y + i][x + j] == 'W') search(s, y + i, x + j);
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<string> s(n + 2);
    s[0] = string(m + 2, '.');
    string tmp;
    for (int i = 1; i < n + 1; ++i) {
        cin >> tmp;
        s[i] = "." + tmp + ".";
    }
    s[n + 1] = string(m + 2, '.');
    int ans = 0;
    for (int y = 1; y < n + 1; ++y) {
        for (int x = 1; x < m + 1; ++x) {
            if (s[y][x] == 'W') {
                ++ans;
                search(s, y, x);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
