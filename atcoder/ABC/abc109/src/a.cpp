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

    int A, B;
    cin >> A >> B;
    if ((A * B) % 2 == 0) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}
