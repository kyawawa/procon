#include <iostream>
#include <iomanip>
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

    int N, M;
    cin >> N >> M;

    int mininum = 0;
    int maximam = 1e6;
    for (int i = 0; i < M; ++i) {
        int L, R;
        cin >> L >> R;

        if (L > mininum) mininum = L;
        if (R < maximam) maximam = R;
    }

    cout << max(0, maximam - mininum + 1) << endl;

    return 0;
}
