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

    int a, b, c;
    int count = 0;
    cin >> a >> b >> c;

    if (a == b) count++;
    if (b == c) count++;
    if (a == c) count++;

    cout << ((3 - count) > 0 ? (3 - count) : 1) << endl;
    return 0;
}
