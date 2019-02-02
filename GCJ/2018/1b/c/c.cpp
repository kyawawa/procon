#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline int sweep(const vector<vector<bool>> _orchard, const int _I, const int _J)
{
    if (_orchard[_I - 1 - 1][_J] and _orchard[_I - 1][_J] and _orchard[_I + 1 - 1][_J]) return sweep(_orchard, _I, _J - 1);
    return _J;
}


// 20 sec or 60 sec
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    for (int _case = 0; _case < T; ++_case) {
        // A: 20 or 200
        // 2 <= I, J <= 999
        // Finish: receive I = J = 0
        int A, I, J, resI, resJ;
        cin >> A;

        std::vector<std::vector<bool>> orchard(1000, vector<bool>(1000, false));

        I = 500;
        J = 999;

        cout << I << " " << J << endl;
        cin >> resI >> resJ;
        J = resJ - 1;
        int initJ = J;

        while (true) {
            if (resI == 0 and resJ == 0) {
                break;
            }
            orchard[resI - 1][resJ - 1] = true;
            if (9 + 3 * (initJ - J) < A) J = sweep(orchard, I, J);
            cout << I << " " << J << endl;
            cin >> resI >> resJ;
        }
    }
}
