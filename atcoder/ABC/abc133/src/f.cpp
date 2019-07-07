#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

// あるxを大きくするか小さくするかで距離が縮まるaが多い方向に進めていく
// queryが
// 奇数 => 真ん中
// 偶数 => 真ん中2つの内の小さい方
// どちらも(num_query - 1) / 2
// 偶数->奇数の時、abs(新しい中央 - 追加された数)だけ増える
// 奇数->偶数の時、abs(元の中央 - 追加された数)だけ増える

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int Q;
    cin >> Q;

    int minimum = -1e9;
    int maximum = 1e9;
    int num_query = 0;
    long long ans = 0;
    multiset<int> a_list;
    multiset<int>::iterator center;

    for (int i = 0; i < Q; ++i) {
        int kind_query;
        cin >> kind_query;

        if (kind_query == 1) {
            int new_a, b;
            cin >> new_a >> b;
            ++num_query;

            int center_num;
            if (num_query % 2 == 0) center_num = *center;

            a_list.insert(new_a);
            center = a_list.cbegin();
            advance(center, (num_query - 1) / 2);

            if (num_query % 2 == 1) center_num = *center;
            ans += abs(center_num - new_a) + b;
        } else {
            cout << *center << " " << ans << "\n";
        }
    }

    cout << flush;
    return 0;
}
