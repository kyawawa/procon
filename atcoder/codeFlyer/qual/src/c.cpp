#include <bits/stdc++.h>
using namespace std;

using lint = long long;

#define REP(i, n)  for(int i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i, n) for(int i=((int)(n)-1); i>=0; --i)

#define EPS 1e-6;

template<class T>bool chMax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chMin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    int N, D;
    scanf("%d %d\n", &N, &D);

    vector<int> X(N), train_idx(N, N);
    REP(i, N) scanf("%d", &X[i]);

    REP(i, N-1) {
        int Xid = X[i] + D;
        for (int j = i + 1; j < N; ++j) {
            if (X[j] - Xid <= 0) continue;
            train_idx[i] = j;
            break; //
        }
    }

    int ans = 0;
    REP(i, N-2) {
        for (int j = i + 1; j < train_idx[i]; ++j) { // j < train_idx[i] - 1
            ans += train_idx[j] - train_idx[i];
        }
    }

    printf("%d\n", ans);

    return 0;
}
