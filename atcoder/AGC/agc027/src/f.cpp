#include <bits/stdc++.h>
using namespace std;

using lint = long long;

#define REP(i,n)    for(int i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i,n)   for(int i=((int)(n)-1);   i>=0; --i)
#define FOR(i,a,n)  for(int i=(a), i##_len=(n); i<i##_len; ++i)

#define EPS 1e-6;

template<class T>bool chMax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chMin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

template <size_t bitsetsize>
void addBit(bitset<bitsetsize>& a, bitset<bitsetsize> b)
{
    while (true) {
        if ((a & b) != 0) {
            auto tmp_a = a;
            a = (tmp_a ^ b);
            b = (tmp_a & b) << 1;
        } else {
            a = a | b;
            break;
        }
    }
}

template <size_t bitsetsize>
void printAns(bitset<bitsetsize>& a, int digits)
{
    RREP(i, digits) cout << a[i];
    cout << "\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, K;
    cin >> N >> M >> K;

    string S, T;
    cin >> S >> T;

    bitset<2000000> X(S), Y(T); // 10^6 + 10^6 bit

    REP(i, K) {
        auto Z = X & Y;
        addBit(X, Z);
        addBit(Y, Z);
    }

    int max_digits = N + max(M, K);
    RREP(i, max_digits) {
        if (X[i]) {
            printAns(X, i+1);
            break;
        }
    }

    RREP(i, max_digits) {
        if (Y[i]) {
            printAns(Y, i+1);
            break;
        }
    }

    return 0;
}
