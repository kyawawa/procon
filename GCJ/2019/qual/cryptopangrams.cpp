#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Plain Textがa b c d e とあった時，ab bc cd deと並ぶので，abとbcの大小でaとcの大きさが分かる
// この結果 L - 1個の不等式が得られる <= 足りない

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

    return 0;
}
