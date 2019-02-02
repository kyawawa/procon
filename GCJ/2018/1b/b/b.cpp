#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline void printAns(const int _case_idx, const int ans)
{
    if (ans < 0) cout << "Case #" << _case_idx + 1 << ": OK" << endl;
    else cout << "Case #" << _case_idx + 1 << ": " << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int _case = 0; _case < T; ++_case) {
        int N;
        cin >> N;

        vector<int> V_odd((N + 1) / 2);
        vector<int> V_eve(N / 2);
        for (int i = 0, odd = 0, eve = 0; i < N; ++i) {
            if (i % 2 == 0) cin >> V_odd[odd++];
            else cin >> V_eve[eve++];
        }

        sort(V_odd.begin(), V_odd.end());
        sort(V_eve.begin(), V_eve.end());

        int ans = -1;
        bool is_odd = true;
        for (int i = 0, odd = 0, eve = 0; i < N - 1; ++i) {
            if (is_odd ? V_odd[odd++] > V_eve[eve] : V_eve[eve++] > V_odd[odd]) {
                ans = i;
                break;
            }
            is_odd = !is_odd;
        }
        printAns(_case, ans);
    }
    return 0;
}
