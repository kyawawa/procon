#include <bits/stdc++.h>
using namespace std;

using lint = long long;

#define REP(i,n)  for(int i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i,n) for(int i=((int)(n)-1); i>=0; --i)

#define EPS 1e-6;

template<class T>bool chMax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chMin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int A, B, N;
    string X;

    cin >> A >> B >> N >> X;

    REP(i, N) {
        if (X[i] == 'S') A = A > 0 ? A - 1 : A;
        else if (X[i] == 'C') B = B > 0 ? B - 1 : B;
        else {
            if (A >= B) A = A > 0 ? A - 1 : A;
            else B = B > 0 ? B - 1 : B;
        }
    }

    cout << A << "\n" << B << "\n";

    return 0;
}
