#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

inline int min(int x)
{
    return (x / 100) * 60 + x % 100;
}

inline int hour(int x)
{
    return (x / 60) * 100 + x % 60;
}

int main()
{
    int n, s, w;
    char c;
    cin >> n;
    vector<pair<int, int> > in(n);
    for (int i = 0; i < n; ++i) {
        cin >> s >> c >> w;
        s = min(s);
        w = min(w);
        s -= s % 5;
        w += 4;
        w -= w % 5;
        in[i] = make_pair(s, w);
    }
    sort(in.begin(), in.end());

    int sout = in[0].first;
    int wout = in[0].second;
    for (int i = 1; i < n; ++i) {
        if (in[i].first > wout) {
            printf("%04d-%04d\n", hour(sout), hour(wout));
            sout = in[i].first;
            wout = in[i].second;
        } else if (in[i].second > wout) {
            wout =in[i].second;
        }
    }
    printf("%04d-%04d\n", hour(sout), hour(wout));

    return 0;
}
