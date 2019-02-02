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

    int K;
    cin >> K;
    int eve = K / 2;
    int odd = K / 2 + K % 2;
    cout << eve * odd << endl;

    return 0;
}
