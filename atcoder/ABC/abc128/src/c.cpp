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

    int N, M;
    cin >> N >> M;

    vector<vector<int>> switches(M);
    for (int i = 0; i < M; ++i) {
        int k;
        cin >> k;
        switches[i].resize(k);
        for (int j = 0; j < k; ++j) cin >> switches[i][j];
    }

    vector<short> p_list(M);
    for (int i = 0; i < M; ++i) cin >> p_list[i];

    return 0;
}
