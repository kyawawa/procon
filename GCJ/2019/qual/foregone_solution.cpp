#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// (N, 0) から始めて，4が出てきたらその桁を1だけ片方に渡す
// stringでやるのが楽そう
// 10^100 の整数は扱えないのでiteratorで回す(多分大丈夫)
// まとめて出力する必要はなかった

inline void printAns(const size_t _case_idx, const string& _a, const string& _b)
{
    cout << "Case #" << _case_idx + 1 << ": " << _a << " " << _b << endl;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    size_t T;
    cin >> T;

    vector<string> a(T);
    vector<string> b(T);

    for (size_t i = 0; i < T; ++i) {
        cin >> a[i]; // N

        bool found_four = false;
        for (auto itr = a[i].begin(); itr != a[i].end(); ++itr) {
            if (*itr == '4') {
                found_four = true;
                *itr = '3';
                b[i].push_back('1');
            } else {
                if (found_four) b[i].push_back('0');
            }
        }
    }

    for (size_t i = 0; i < T; ++i) {
        printAns(i, a[i], b[i]);
    }
    return 0;
}
