#include <bits/stdc++.h>
using namespace std;

using lint = long long;

#define REP(i, n)  for(int i=0, i##_len=(n); i<i##_len; ++i)
#define RREP(i, n) for(int i=((int)(n)-1); i>=0; --i)

#define EPS 1e-6;

template<class T>bool chMax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chMin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

// https://stackoverflow.com/questions/109023/how-to-count-the-number-of-set-bits-in-a-32-bit-integer
int numberOfSetBits(int i)
{
     i = i - ((i >> 1) & 0x55555555);
     i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
     return (((i + (i >> 4)) & 0x0F0F0F0F) * 0x01010101) >> 24;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int H, W, N, M;
    cin >> H >> W >> N >> M;
    vector<string> A(N);
    vector<unsigned int> A_bit(N, 0);

    int row_slide = H - N;
    int col_slide = W - M;

    REP(i, N) {
        cin >> A[i];
        REP(j, M) {
            if (A[i][j] == '#') A_bit[i] += (int)pow(2, j);
        }

        REP(j, col_slide + 1) {
            A_bit[i] = A_bit[i] | (A_bit[i] << 1);
        }
    }

    vector<unsigned int> ans_bit(H, 0);
    REP(i, N) {
        REP(j, row_slide + 1) {
            cout << "i: " << i << "j: " << j << endl;
            ans_bit[i + j] = ans_bit[i + j] | A_bit[i];
        }
    }

    int ans = 0;
    REP(i, H) ans += numberOfSetBits(ans_bit[i]);

    cout << ans << "\n";

    return 0;
}
