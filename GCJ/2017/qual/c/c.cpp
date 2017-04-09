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
    int T;
    cin >> T;
    long long int N, K;
    vector<pair<long long int, long long int> > block(2), next_block(2);
    for (int t = 0; t < T; ++t) {
        cin >> N >> K;
        block[0] = make_pair(N, 1);
        vector<long long int> ans(2);
        int nob = 1; // num of blocks
        for (long long int i = 0; i < K; ++i) {
            long long int tmp_num = 0;
            for (int j = 0; j < nob; ++j) {
                tmp_num += block[j].second;
            }
            if (tmp_num < K - i) { // cant fill
                vector<long long int> tmp_second(2, 0);
                next_block[0].second = 0;
                next_block[1].second = 0;
                for (int j = 0; j < nob; ++j) {
                    if (block[j].first % 2 == 0) {
                        next_block[0].first = block[j].first / 2;
                        next_block[1].first = (block[j].first - 1) / 2;
                        next_block[0].second += block[j].second;
                        next_block[1].second += block[j].second;
                        nob = 2;
                        if (block[j].first % 2 == 0) nob = 1;
                    } else {
                        if (nob == 1) next_block[j].first = (block[j].first - 1) / 2;
                        next_block[j].second += block[j].second * 2;
                    }
                }
                block = next_block;
            } else {
                long long int num = 0;
                for (int j = 0; j < nob; ++j) {
                    num += block[j].second;
                    // cout << "K-i: " << K-i << ", num: " << num << ", first: " << block[i].first << endl;
                    if (K - i <= num) {
                        if (block[j].first % 2 == 0) {
                            ans[0] = block[j].first / 2;
                            ans[1] = (block[j].first - 1) / 2;
                        } else {
                            ans[0] = ans[1] = (block[j].first - 1) / 2;
                        }
                        i = K;
                        break;
                    }
                }
            }
        }
        cout << "Case #" << t + 1 << ": " << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}
