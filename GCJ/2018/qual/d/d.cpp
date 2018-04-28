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
        double A; // 6 digits after the decimal point
        cin >> A;

        double r;
        double y;
        if (A == 1.0) {
            r = 0;
            y = 0;
        } else if (A == 1.414213) {
            r = M_PI / 4;
            y = 0;
        }
        // Just rotate X axis
        else if (A <= 1.414213) {
            //
            r = M_PI / 8;

        } else { // Must rotate X and Z axis
        }
    return 0;
}
