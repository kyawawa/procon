#include <bits/stdc++.h>
using namespace std;

using lint = long long;

#define REP(i,n)    for(int i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i,n)   for(int i=((int)(n)-1);   i>=0; --i)
#define FOR(i,a,n)  for(int i=(a), i##_len=(n); i<i##_len; ++i)

#define EPS 1e-6;

template<class T>bool chMax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chMin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// その時の一番遠い区間を足していく
// MAX, MINでそれぞれソート
// 交互にうつる

int main()
{
    int N;
    scanf("%d", &N);

    // vector<pair<int, int>> L_max(N), L_min(N);
    // REP(i, N) scanf("%d %d\n", &L_max[i].first, &L_max[i].second);
    vector<pair<pair<int, int>, int>> L_max(N), L_min(N);
    REP(i, N) {
        scanf("%d %d", &L_max[i].first.first, &L_max[i].first.second);
        L_max[i].second = i;
    }

    copy(L_max.begin(), L_max.end(), L_min.begin());

    // second が小さい順
    sort(L_min.begin(), L_min.end(),
         [](const pair<pair<int, int>, int>& x, const pair<pair<int, int>,int>& y)
         { return x.first.second < y.first.second; }
         );

    // firstが大きい順
    sort(L_max.begin(), L_max.end(), greater<pair<pair<int, int>, int>>());

    lint ans = 0;
    int point = 0;
    vector<int> is_used(N, false);
    for (int count = 0, imin = 0, imax = 0;;) {
        while (is_used[L_max[imax].second]) ++imax;
        if (point < L_max[imax].first.first) {
            ans += abs(L_max[imax].first.first - point);
            point = L_max[imax].first.first;
        }
        is_used[L_max[imax].second] = true;
        ++imax;
        ++count;
        if (count == N) break;

        while (is_used[L_min[imin].second]) ++imin;
        if (point > L_min[imin].first.second) {
            ans += abs(L_min[imin].first.second - point);
            point = L_min[imin].first.second;
        }
        is_used[L_min[imin].second] = true;
        ++imin;
        ++count;
        if (count == N) break;
    }

    ans += abs(point);
    printf("%lld\n", ans);

    return 0;
}
