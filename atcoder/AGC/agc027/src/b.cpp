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
    lint X;

    cin >> N >> X;
    vector<lint> x(N);
    REP(i, N) cin >> x[i];

    int  carry = 0;
    lint pos = 0;
    lint ans = 0;

    // RREP(i, N) {
    //     ans += abs(pos - x[i]) * (carry + 1) * (carry + 1) + X;
    //     pos = x[i];
    //     ++carry;

    //     if (i > 0 && x[i - 1] * (2 * carry - 1) - x[i - 1] - X < 0) continue; // carry one more item;
    //     ans += pos * (carry + 1) * (carry + 1) + X;
    //     pos = 0;
    //     carry = 0;
    // }

    int remain = N;
    vector<bool> is_remaining(N, true);

    for (int i = N - 1; remain > 0; --i) {
        if (is_remaining[i]) {
            if (x[i] * (2 * carry - 1) - x[i] - X < 0) {
                if (!(carry > 1 && remain - i - 1 > 0)) {
                    ans += abs(pos - x[i]) * (carry + 1) * (carry + 1) + X;
                    pos = x[i];
                    ++carry;
                    --remain;
                    is_remaining[i] = false;
                }
            }
        }

        if (i == 0) {
            ans += pos * (carry + 1) * (carry + 1) + X;
            pos = 0;
            carry = 0;
            i = N - 1;
        }
    }

    cout << ans << endl;

    return 0;
}
