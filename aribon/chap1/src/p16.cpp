#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// input:
// n
// a1 a2 a3 ... an
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<int>()); // decreasing
    for (int i = 0; i < n - 2; ++i) {
        if (a[i] < a[i+1] + a[i+2]) {
            cout << a[i] + a[i+1] + a[i+2] << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}
