#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int h1, h2, w1, w2;
    cin >> h1 >> w1;
    cin >> h2 >> w2;
    if (h1 == h2 || w1 == w2 || w1 == h2 || h1 == w2) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
