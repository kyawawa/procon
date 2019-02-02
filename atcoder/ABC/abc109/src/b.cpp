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

    int N;
    cin >> N;

    vector<string> W(N);
    char last_char;
    string ans = "Yes";

    for (int i = 0; i < N; ++i) {
        cin >> W[i];

        if (i != 0 && last_char != W[i][0]) {
            ans = "No";
        }

        if (find(W.begin(), W.end(), W[i]) != W.begin() + i) {
            ans = "No";
        }

        last_char = W[i].back();
    }
    cout << ans << endl;

    return 0;
}
