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
    cin >> N;
    vector<int> a(N);
    double ave = 0;
    REP(i, N) {
        cin >> a[i];
        ave += a[i];
    }

    ave /= N;

    double min_dist = ave;
    int idx = 0;

    REP(i, N) {
        double dist = abs(a[i] - ave);
        if (dist < min_dist) {
            min_dist = dist;
            idx = i;
        }
    }

    cout << idx << endl;

    return 0;
}
