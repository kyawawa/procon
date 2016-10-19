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

    string s;
    cin >> s;

    long long g, p = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'g') g++;
        else p++;
    }

    long long ans = 0;
    long long my_p = s.size() / 2;
    long long my_g = s.size() - my_p;

    if (my_p > g) {
        ans += g;
        ans -= my_g;
    } else {
        ans += my_p;
        ans -= p;
    }

    cout << ans << endl;

    return 0;
}
