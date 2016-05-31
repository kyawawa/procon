#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    if (m == 0) {
        cout << 1 << endl;
        return 0;
    }
    vector<pair<int, int> > x(m);
    for (int i = 0; i < m; i ++) {
        cin >> x[i].first >> x[i].second;
    }
    return 0;
}
