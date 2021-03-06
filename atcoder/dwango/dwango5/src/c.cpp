#include <bits/stdc++.h>
using namespace std;

using lint = long long;

#define REP(i,n)    for(int i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i,n)   for(int i=((int)(n)-1);   i>=0; --i)
#define FOR(i,a,n)  for(int i=(a), i##_len=(n); i<i##_len; ++i)

#define EPS 1e-6;

template<class T>bool chMax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chMin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

inline int k_dmc (const int k, const vector<int>& DMC)
{
    int num_k_dmc = 0;
    REP(i, k) {
        num_k_dmc += DMC[i];
    }
    return num_k_dmc;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S;
    int Q;
    cin >> N >> S >> Q;
    vector<int> k(Q);
    REP(i, Q) cin >> k[i];

    vector<pair<int, int>> d_m; // d_idx, num_m after d_idx
    d_m.reserve(N);

    vector<lint> DMC(Q, 0);

    int num_d = 0;
    REP(i, N) {
        if (S[i] == 'D') {
            d_m.push_back(make_pair(i, 0));
            ++num_d;
        } else if (S[i] == 'M') {
            REP(j, num_d) {
                d_m[j].second += 1;
            }
        } else if (S[i] == 'C') {
            REP(j, num_d) {
                REP(k_idx, Q) {
                    if (i - d_m[j].first < k[k_idx])
                        DMC[k_idx] += d_m[j].second;
                }
            }
        }
    }

    REP(i, Q) {
        cout << DMC[i] << endl;
    }

    return 0;
}
