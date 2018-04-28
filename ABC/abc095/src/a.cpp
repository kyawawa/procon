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

    string S;
    cin >> S;

    int ans = 700;
    for (int i = 0; i < 3; ++i) {
        if (S[i] == 'o') ans += 100;
    }

    cout << ans << endl;

    return 0;
}
