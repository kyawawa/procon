#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// It should solve one searching

inline void printAns(const int _case_idx, const int ans)
{
    if (ans < 0) cout << "Case #" << _case_idx + 1 << ": IMPOSSIBLE" << endl;
    else cout << "Case #" << _case_idx + 1 << ": " << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    vector<int> D(T);
    vector<string> P(T);

    for (int i = 0; i < T; ++i) {
        cin >> D[i] >> P[i];
    }

    for (int _case = 0; _case < T; ++_case) {
        int max_damage = 0;
        // int damage = 1;
        int S[30] = {0};
        for (int i = 0, c_count = 0, damage = 1; i < P[_case].size(); ++i) {
            if (P[_case][i] == 'S') {
                ++S[c_count];
                max_damage += damage;
            } else {
                ++c_count;
                damage *= 2;
            }
        }

        int diff = max_damage - D[_case];

        int i = P[_case].size() - 1;
        int ans = 0;
        while (i > 0) {
            if (diff <= 0) {
                printAns(_case, ans);
                break;
            }
            if (S[i] > 0) {
                --S[i];
                ++S[i - 1];
                ++ans;
                diff -= pow(2, i - 1);
            } else --i;
        }

        if (i == 0) printAns(_case, -1);
    }
    return 0;
}
