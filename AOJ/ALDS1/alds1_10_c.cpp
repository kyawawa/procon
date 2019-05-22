#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Dynamic Programming - LCS

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int q;
    cin >> q;

    for (int _ = 0; _ < q; ++_) {
        string s1, s2;
        cin >> s1 >> s2;

        const int s1_size = s1.size();
        const int s2_size = s2.size();
        vector<vector<int>> dp(s1_size + 1);
        for (int i = 0; i < s1_size + 1; ++i) dp[i].resize(s2_size + 1, 0);

        for (int i = 0; i < s1_size; ++i) {
            for (int j = 0; j < s2_size; ++j) {
                if (s1[i] == s2[j]) dp[i+1][j+1] = dp[i][j] + 1;
                else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
            }
        }
        cout << dp[s1_size][s2_size] << "\n";
    }

    cout << flush;
    return 0;
}
