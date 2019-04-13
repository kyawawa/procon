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

    int a, e, tmp, k;
    cin >> a >> tmp >> tmp >> tmp >> e >> k;

    cout << (e - a <= k ? "Yay!" : ":(") << endl;
    return 0;
}
