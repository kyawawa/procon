#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 四捨五入した投票率の和の最大値を求める
// 繰り上げの言語の和を最大化する

inline void printAns(const int _case_idx, const int ans)
{
    cout << "Case #" << _case_idx + 1 << ": " << ans << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    int num_peo, num_lan;

    for (int _case = 0; _case < T; ++_case) {
        cin >> num_peo >> num_lan;

        vector<double> C(num_lan);
        double rate = 100.0 / num_peo;
        double tmp_d;
        int sum_Ci = 0;
        {
            double rate_shousu = modf(rate, &tmp_d);
            int tmp_C;
            for (int i = 0; i < num_lan; ++i) {
                cin >> tmp_C;
                sum_Ci += tmp_C;
                C[i] = rate_shousu * tmp_C;
            }
        }

        sort(C.begin(), C.end(), greater<double>());
        double up_rate = modf(100.0 / num_peo, &tmp_d);

        for (int i = 0, idx = 0; i < num_peo - sum_Ci; ++i) {
            if (modf(C[idx], &tmp_d) < 0.5) C[idx] += up_rate;
            else {
                ++idx;
                if (idx >= num_lan) C.push_back(up_rate);
                else --i;
            }
        }

        int num_up = 0;
        for (int i = 0; i < C.size(); ++i) {
            num_up += static_cast<int>(C[i] + 0.5);
        }

        int ans = static_cast<int>(rate) * num_peo + num_up;
        printAns(_case, ans);
    }

    return 0;
}
