#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <tuple>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<tuple<string, int, int>> rest;
    rest.reserve(N);
    for (int i = 0; i < N; ++i) {
        string s;
        int point;
        int id = i + 1;
        cin >> s >> point;
        rest.emplace_back(s, -point, id);
    }

    sort(rest.begin(), rest.end());
    for (int i = 0; i < N; ++i) {
        cout << get<2>(rest[i]) << endl;
    }

    return 0;
}
