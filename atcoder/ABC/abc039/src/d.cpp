#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

void dot(vector<string> &s, int i, int j)
{
    int row = s.size() - 1;
    int col = s[0].size() - 1;
    for (int k = -1; k < 2; ++k) {
        for (int h = -1; h < 2; ++h) {
            s[min(row, max(0, i + k))][min(col, max(0, j + h))] = '.';
        }
    }
}

void sharp(vector<string> &s, int i, int j)
{
    int row = s.size() - 1;
    int col = s[0].size() - 1;
    for (int k = -1; k < 2; ++k) {
        for (int h = -1; h < 2; ++h) {
            s[min(row, max(0, i + k))][min(col, max(0, j + h))] = '#';
        }
    }
}

bool restore(vector<string> &s)
{
    vector<string> s_org = s;
    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s[0].size(); ++j) {
            if (s[i][j] == '.') dot(s_org, i, j);
        }
    }

    vector<string> s_rest = s_org;

    for (int i = 0; i < s.size(); ++i) {
        for (int j = 0; j < s[0].size(); ++j) {
            if (s_org[i][j] == '#') sharp(s_rest, i, j);
        }
    }

    if (s_rest == s) {
        s = s_org;
        return true;
    }
    return false;
}

int main()
{
    int h, w;
    cin >> h >> w;
    vector<string> s(h);
    for (int i = 0; i < h; ++i) {
        cin >> s[i];
    }

    if (restore(s)) {
        cout << "possible" << endl;
        for (int i = 0; i < s.size(); ++i) {
            cout << s[i] << endl;
        }
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
