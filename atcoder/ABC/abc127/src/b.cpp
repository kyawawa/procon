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

    int r, D, x;
    cin >> r >> D >> x;

    for (int i = 0; i < 10; ++i) {
        x = r * x - D;
        cout << x << "\n";
    }
    cout << flush;;

    return 0;
}
