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
    string o, e;
    cin >> o;
    cin >> e;
    int i;
    for (i = 0; i < e.size(); ++i) {
        cout << o[i] << e[i];
    }
    if (o.size() > e.size()) cout << o[i];
    cout << endl;
    return 0;
}
