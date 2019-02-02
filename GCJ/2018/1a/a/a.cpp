#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline void printAns(const int _case_idx, const int ans)
{
    if (ans < 0) cout << "Case #" << _case_idx + 1 << ": IMPOSSIBLE" << endl;
    else cout << "Case #" << _case_idx + 1 << "POSSIBLE" << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    int R, C, H, V;
    for (int _case = 0; _case < T; ++_case) {
        cin >> R >> C >> H >> V;
        vector<string> grid(R);
        int num_chips = 0;
        for (int i = 0; i < R; ++i) {
            cin >> grid[i];
            num_chips += std::count(grid[i].begin(), grid[i].end(), '@');
        }


    }

    return 0;
}
