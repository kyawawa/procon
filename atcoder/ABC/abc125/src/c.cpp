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
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    // 左から1つずつ要素を増やすgcdと、
    // 右から1つずつ要素を減らすgcdをリスト保持
    // 特に、右からのやつをリスト保持しないと計算量が大変なことになる
    // gcdは要素を足せるが減らせない

    vector<int> left_gcd(N);
    vector<int> right_gcd(N);
    left_gcd[0] = 0;
    right_gcd[N-1] = 0;

    for (int i = 1; i < N; ++i) {
        left_gcd[i] = gcd(left_gcd[i-1], A[i-1]);
        right_gcd[N-i-1] = gcd(right_gcd[N-i], A[N-i]);
    }

    int max_gcd = 1;
    for (int i = 0; i < N; ++i) {
        max_gcd = max(max_gcd, gcd(left_gcd[i], right_gcd[i]));
    }
    cout << max_gcd << endl;

    return 0;
}
