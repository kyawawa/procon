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

    int N;
    lint x;

    cin >> N >> x;
    vector<lint> a(N);

    REP(i, N) { cin >> a[i]; }

    sort(a.begin(), a.end());
    lint ans = 0;

    for (int i = 0; i < N; ++i) {
        if (x >= a[i]) {
            x -= a[i];
            if (i < N - 1 || x == 0) ++ans;
        } else break;
    }

    cout << ans << endl;

    return 0;
}
