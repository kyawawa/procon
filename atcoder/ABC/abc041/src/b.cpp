#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    long long int a, b, c, d;
    cin >> a >> b >> c;
    d = (long long int)1e9 + 7;
    cout << a % d * b % d * c % d << endl;

    return 0;
}
