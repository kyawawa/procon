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
    int a, b, h;
    cin >> a;
    cin >> b;
    cin >> h;

    cout << (a + b) * h / 2 << endl;

    return 0;
}
