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

    int A, B, T;
    cin >> A >> B >> T;
    cout << (T / A) * B << endl;
    return 0;
}
