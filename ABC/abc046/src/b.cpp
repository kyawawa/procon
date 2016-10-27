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

    long long int n, k;
    cin >> n >> k;

    cout << (long long int)(k * pow(k-1, n-1)) << endl;
    return 0;
}
