#include <bits/stdc++.h>
using namespace std;

using lint = long long;

#define REP(i,n)    for(int i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i,n)   for(int i=((int)(n)-1);   i>=0; --i)
#define FOR(i,a,n)  for(int i=(a), i##_len=(n); i<i##_len; ++i)

#define EPS 1e-6;

template<class T>bool chMax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chMin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    REP(i, N) cin >> a[i];

    vector<lint> beaut(N * (N + 1) / 2);
    int idx = 0;
    REP(i, N) {
        beaut[idx] = a[i];
        idx++;
        FOR(j, i + 1, N) {
            beaut[idx] = beaut[idx - 1] + a[j];
            idx++;
        }
    }


    return 0;
}
