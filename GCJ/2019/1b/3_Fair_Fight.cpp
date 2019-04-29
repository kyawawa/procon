#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
using namespace std;

// TLE for Test set 2 (N = 10^5 for 8 test cases and N <= 1000 for all but 8)

inline void printAns(const size_t case_idx, const size_t result)
{
    cout << "Case #" << case_idx + 1 << ": " << result << endl;;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    size_t T;
    cin >> T;

    for (size_t i = 0; i < T; ++i) {
        size_t N, K;
        cin >> N >> K;

        vector<size_t> A(N);
        vector<size_t> B(N);
        for (size_t j = 0; j < N; ++j) cin >> A[j];
        for (size_t j = 0; j < N; ++j) cin >> B[j];

        size_t result = 0;
        for (size_t j = 0; j < N; ++j) {
            int max_A = A[j];
            int max_B = B[j];
            for (size_t k = j; k < N; ++k) {
                if (max_A < A[k]) max_A = A[k];
                if (max_B < B[k]) max_B = B[k];
                if (abs(max_A - max_B) <= K) ++result;
            }
        }

        printAns(i, result);
    }
    return 0;
}
