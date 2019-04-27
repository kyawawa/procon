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

// fail1
// 1個抜きのGCDをN個求め、その最大値が答え
// 時間が間に合わない
// int main()
// {
//     cin.tie(0);
//     ios::sync_with_stdio(false);

//     int N;
//     cin >> N;
//     vector<int> A(N);
//     for (int i = 0; i < N; ++i) cin >> A[i];

//     int max_gcd = 1;
//     for (int i = 0; i < N; ++i) {
//         int tmp_gcd = 0;
//         for (int j = 0; j < N; ++j) {
//             if (i == j) continue;
//             if (tmp_gcd == 0) {
//                 tmp_gcd = A[j];
//                 continue;
//             }
//             tmp_gcd = gcd(tmp_gcd, A[j]);
//         }
//         max_gcd = max(max_gcd, tmp_gcd);
//     }

//     cout << max_gcd << endl;

//     return 0;
// }

// fail2
// 明らかに間違い
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];

    vector<int> gcd_list(N);
    for (int i = 0; i < N - 1; ++i) {
        gcd_list[i] = gcd(A[i], A[i+1]);
    }
    gcd_list[N-1] = gcd(A[N-1], A[0]);
    sort(gcd_list.begin(), gcd_list.end(), greater<int>());

    int max_gcd = gcd_list[0];
    for (int i = 1; i < N - 2; ++i) { // ボトルネックを含むgcdは2つ
        max_gcd = gcd(max_gcd, gcd_list[i]);
    }

    cout << max_gcd << endl;

    return 0;
}
