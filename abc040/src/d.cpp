#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

int solve(const vector<pair<int, pair<int, int> > > &road, const pair<int, pair<int, int> > &p, vector<int> &city)
{
    static int start = 0;
    static int road_size = road.size();

    while (road[start].first > p.first && start < road_size) {
        int a = city[road[start].second.first - 1];
        int b = city[road[start].second.second - 1];
        if (a != b) {
            int min = a < b ? a : b;
            int max = a > b ? a : b;
            int size = city.size();
            for (int i = 0; i < size; ++i) {
                if (city[i] == max) city[i] = min;
            }
        }
        ++start;
    }

    return count(city.begin(), city.end(), city[p.second.first - 1]);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m, q;

    cin >> n >> m;
    vector<pair<int, pair<int, int> > > road(m);
    for (int i = 0; i < m; ++i) {
        cin >> road[i].second.first >> road[i].second.second >> road[i].first;
    }
    cin >> q;
    vector<pair<int, pair<int, int> > > pv(q);
    for (int i = 0; i < q; ++i) {
        cin >> pv[i].second.first >> pv[i].first;
        pv[i].second.second = i;
    }

    sort(road.begin(), road.end(), greater<pair<int, pair<int, int> > >());
    sort(pv.begin(), pv.end(), greater<pair<int, pair<int, int> > >());

    vector<int> city(n);
    iota(city.begin(), city.end(), 1);

    vector<int> ans(q);
    for (int i = 0; i < q; ++i) {
        ans[pv[i].second.second] = solve(road, pv[i], city);
    }
    for (int i = 0; i < q; ++i) {
        cout << ans[i] <<endl;
    }

    return 0;
}
