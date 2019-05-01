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

    size_t N = S.size();
    int ans = 0;

    for (size_t i = 0; i < N - 1; ++i) {
        if (S[i] == S[i+1]) {
            S[i+1] = (S[i] == '0') ? '1' : '0';
            ++ans;
        }
    }

    cout << ans << endl;
    return 0;
}
