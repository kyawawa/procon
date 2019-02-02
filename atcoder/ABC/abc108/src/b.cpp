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

    int p[4][2];
    cin >> p[0][0] >> p[0][1] >> p[1][0] >> p[1][1];

    for (int i = 0; i < 2; ++i) {
        p[i + 2][0] = p[i + 1][0] - (p[i + 1][1] - p[i][1]);
        p[i + 2][1] = p[i + 1][1] + (p[i + 1][0] - p[i][0]);
    }
    cout << p[2][0] << " " << p[2][1] << " " << p[3][0] << " " << p[3][1] << endl;

    return 0;
}
