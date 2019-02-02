#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline void coutAns(int y1, int x1, int y2, int x2)
{
    cout << y1 + 1 << " " << x1 + 1 << " " << y2 + 1 << " " << x2 + 1 << "\n";
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W;
    cin >> H >> W;
    vector<vector<int>> a(H);

    for (int i = 0; i < H; ++i) {
        a[i].resize(W);
        for (int j = 0; j < W; ++j) {
            cin >> a[i][j];
            if (a[i][j] % 2 == 0) a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    int to_right = 1;
    int j;
    pair<int, int> first = make_pair<int, int>(0, 0);
    bool found_first = false;
    int N = 0;

    for (int i = 0; i < H; ++i) {
        if (to_right == 1) j = 0;
        else j = W - 1;
        while (j >= 0 && j < W) {
            if (a[i][j] == 1) {
                if (!found_first) {
                    first = pair<int, int>(i, j);
                    found_first = true;
                } else {
                    if (i - first.first * to_right > 0) {
                        for (int k = first.second; k < j; k += to_right) {
                            coutAns(first.first, k, first.first, k + to_right);
                            ++N;
                        }
                        for (int k = first.first; k < i; ++k) {
                            coutAns(k, i, k + 1, i);
                            ++N;
                        }
                    } else {
                        for (int k = first.first; k < i; ++k) {
                            coutAns(k, first.second, k + 1, first.second);
                            ++N;
                        }
                        for (int k = first.second; k >= j; k += to_right) {
                            coutAns(i, k, i, k + to_right);
                            ++N;
                        }
                    }

                    found_first = false;
                }
            }

            j += to_right;
        }
        to_right *= -1;
    }

    printf("%d\n", N);
    cout << flush;
    return 0;
}
