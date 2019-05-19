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

    int a = stoi(S.substr(0, 2));
    int b = stoi(S.substr(2, 2));

    bool a_can_mm = false;
    bool b_can_mm = false;

    if (a > 0 && a < 13) a_can_mm = true;
    if (b > 0 && b < 13) b_can_mm = true;

    string ans;
    if (a_can_mm && b_can_mm) ans = "AMBIGUOUS";
    else if (a_can_mm && !b_can_mm) ans = "MMYY";
    else if (!a_can_mm && b_can_mm) ans = "YYMM";
    else ans = "NA";

    cout << ans << endl;

    return 0;
}
