#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

void calcMaxForEachK(vector<int>& vec, const vector<int>& V, const int K)
{
    vec.resize(K + 1, 0);
    multiset<int> minus_stack;
    for (int i = 1; i <= K; ++i) {
        if (V[i - 1] > 0) {
            if (minus_stack.size() > 0)

            if (minus_stack.size() == 0 ||
                *minus_stack.cbegin() > -V[i - 1]) vec[i] = vec[i - 1] + V[i - 1];
            else if (*minus_stack.cbegin() <= -V[i - 1]) {
                vec[i] = vec[i - 1] - *minus_stack.cbegin();
                minus_stack.erase(*minus_stack.cbegin());
            }
        } else {
            minus_stack.insert(V[i - 1]);
            vec[i] = vec[i - 1];
        }
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<int> V(N);
    for (int i = 0; i < N; ++i) cin >> V[i];

    // size: K+1 (left_max[0] == 0)
    vector<int> left_max;
    vector<int> right_max;

    calcMaxForEachK(left_max, V, K);
    reverse(V.begin(), V.end());
    calcMaxForEachK(right_max, V, K);

    int ans = 0;
    for (int i = 0; i <= K; ++i) {
        ans = max(left_max[i] + right_max[K - 1], ans);
    }

    cout << ans << endl;

    return 0;
}
