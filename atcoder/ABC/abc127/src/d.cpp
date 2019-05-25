#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    vector<pair<int, int>> CB(M);
    for (int i = 0; i < M; ++i) cin >> CB[i].second >> CB[i].first;
    sort(CB.begin(), CB.end(), greater<pair<int, int>>());

    int i = 0;
    int j = 0;
    long long ans = 0;
    while (j < N && i < M) {
        if (CB[i].first <= A[j]) break;
        // A[j] = CB[i].first;
        ans += CB[i].first;
        --CB[i].second;
        ++j;
        if (CB[i].second == 0) ++i;
    }

    while (j < N) ans += A[j++];
    cout << ans << endl;

    return 0;
}
