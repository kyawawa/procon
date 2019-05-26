#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// X - Ti to X - Si
// 複数あったら手前ので引っかかる

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);


    int N, Q;
    cin >> N >> Q;

    vector<int> work_start(N);
    vector<int> work_end(N);
    vector<int> work_place(N);
    for (int i = 0; i < N; ++i) cin >> work_start[i] >> work_end[i] >> work_place[i];

    vector<int> man_start(Q);
    for (int i = 0; i < Q; ++i) cin >> man_start[i];



    return 0;
}
