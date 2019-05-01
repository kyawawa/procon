#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;

// 0のブロックが始まるときにtmp_ansとansの大小確認、dequeの先頭をtmp_ansから引く、dequeのpopを行う
// それ以外は、1と0のブロックの積算を次々足していく
// 1のブロックが始まるときに1と0のブロックの数をdequeにpushする
// だらだらと実装にめっちゃかかった．始点処理など、if文が入れ子になる問題に慣れたい

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    string S;

    cin >> N >> K >> S;
    deque<int> zero_list;

    bool is_zero_continuous = false;
    int num_one_and_zero = 0; // sum of zeros and ones just before zeros
    int tmp_ans = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == '0') {
            if (!is_zero_continuous && zero_list.size() == K) {
                if (tmp_ans > ans) ans = tmp_ans; // 減らす前に確認
                tmp_ans -= zero_list.front();
                zero_list.pop_front();
            }
            is_zero_continuous = true;
            ++num_one_and_zero;
            ++tmp_ans;
        } else {
            if (is_zero_continuous) {
                is_zero_continuous = false;
                zero_list.push_back(num_one_and_zero);
                num_one_and_zero = 0;
            }
            ++num_one_and_zero;
            ++tmp_ans;
        }
    }

    if (tmp_ans > ans) ans = tmp_ans;
    cout << ans << endl;

    return 0;
}
