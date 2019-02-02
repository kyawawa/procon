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

    int A, B;
    cin >> A >> B;

    cout << A - A % B << "\n";
    return 0;
}
