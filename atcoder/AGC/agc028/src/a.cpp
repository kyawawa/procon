#include <bits/stdc++.h>
using namespace std;

unsigned int gcd(unsigned int u, unsigned int v) {
    while (v != 0) {
        unsigned int r = u % v;
        u = v;
        v = r;
    }
    return u;
}

unsigned int lcm (unsigned int a, unsigned int b)
{
    if ((a == 0) || (b == 0)) return 0;
    return a * b / gcd(a, b);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    string S, T;

    cin >> N >> M >> S >> T;

    int LCM = lcm(N, M);

    int S_step = LCM / M;
    int T_step = LCM / N;

    int n = 0;
    int m = 0;

    while (n < N && m < M) {
        if (S[n] != T[m]) {
            cout << -1 << endl;
            return 0;
        }

        n += S_step;
        m += T_step;
    }

    cout << LCM << endl;
    return 0;
}
