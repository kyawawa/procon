#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template<class T>
T gcd(T a, T b)
{
    if (a == 0) return b;
    else if (b == 0) return a;

    if (b > a) swap(a, b); // assume a >= b

    T ret = b;
    while (a % b != 0) {
        ret = a % b;
        a = b;
        b = ret;
    }
    return ret;
}


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    long long int X;
    cin >> N >> X;

    long long int tmp_x;
    long long int ans = 0;
    for (int i = 0; i < N; ++i) {
        cin >> tmp_x;
        ans = gcd(ans, abs(tmp_x - X));
    }
    cout << ans << endl;

    return 0;
}
