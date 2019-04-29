#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;

// smallest x and y
// MLE for Test set 2 (Q = 10^5)

inline void printAns(const size_t case_idx, const size_t x, const size_t y)
{
    cout << "Case #" << case_idx + 1 << ": ";
    cout << x << " " << y << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    size_t T;
    cin >> T;
    size_t P, Q;

    for (size_t i = 0; i < T; ++i) {
        cin >> P >> Q;
        Q += 1; // Hot fix
        vector<vector<size_t>> count(Q);
        for (size_t j = 0; j < Q; ++j) count[j].resize(Q, 0);

        for (size_t j = 0; j < P; ++j) {
            size_t x, y;
            char direction;
            cin >> x >> y >> direction;

            switch(direction) {
              case 'N':
                  for (int k = 0; k < Q; ++k) {
                      for (int l = y + 1; l < Q; ++l) {
                          ++count[k][l];
                      }
                  }
                  break;
              case 'S':
                  for (int k = 0; k < Q; ++k) {
                      for (int l = y - 1; l >= 0; --l) {
                          ++count[k][l];
                      }
                  }
                  break;
              case 'E':
                  for (int k = x + 1; k < Q; ++k) {
                      for (int l = 0; l < Q; ++l) {
                          ++count[k][l];
                      }
                  }
                  break;
              case 'W':
                  for (int k = x - 1; k >= 0; --k) {
                      for (int l = 0; l < Q; ++l) {
                          ++count[k][l];
                      }
                  }
                  break;
              default:
                  cout << "ERROR" << endl;
            }
        }

        size_t max_count = 0;
        size_t min_x, min_y;
        for (size_t k = 0; k < Q; ++k) {
            for (size_t l = 0; l < Q; ++l) {
                if (count[k][l] > max_count) {
                    max_count = count[k][l];
                    min_x = k;
                    min_y = l;
                }
            }
        }

        printAns(i, min_x, min_y);
    }
    return 0;
}
