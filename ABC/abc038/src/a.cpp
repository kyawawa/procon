#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s[s.size() - 1] == 'T') cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
