#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << 2 * (a * b + b * c + c * a) << endl;
    return 0;
}
