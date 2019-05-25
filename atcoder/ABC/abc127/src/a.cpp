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

    int A, B;
    cin >> A >> B;

    int ans = B;
    if (A <= 5) ans = 0;
    else if (A <= 12) ans /= 2;
    cout << ans << endl;

    return 0;
}
