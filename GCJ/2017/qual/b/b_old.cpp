#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

inline bool find_min(const string& s, vector<long long int>& n, vector<long long int> &digit)
{
    vector<char> num;
    num.push_back(s[0]);
    digit.push_back(1);
    int size = num.size();
    for (long long int i = 1; i < s.size(); ++i) {
        if (s[i] == '0') return false;
        if (num[size-1] < s[i]) {
            num.push_back(s[i]);
            digit.push_back(i+1);
            ++size;
            continue;
        }
        for (int j = 0; j < size; ++j) {
            if (s[i] < num[j]) {
                size = j + 1;
                num.resize(size);
                digit.resize(size);
                num[j] = s[i];
                digit[j] = i + 1;
            }
        }
    }
    n.resize(size);
    for (int i = 0; i < size; ++i) {
        n[i] = num[i] - '0';
    }
    return true;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    string N;
    for (int i = 0; i < T; ++i) {
        cin >> N;
        string ans = "";
        vector<long long int> min_num, min_digit;
        if (N.size() == 1) ans = N;
        else if (!find_min(N, min_num, min_digit)) ans = string(N.size() - 1, '9');
        else {
            long long int prev_digit = 0;
            for (int j = 0; j < min_num.size(); ++j) {
                string tmp_str = to_string(min_num[j]);
                for (long long int k = 0; k < min_digit[j] - prev_digit; ++k) {
                    ans += tmp_str;
                }
                prev_digit = min_digit[j];
            }
            if (ans[ans.size() - 2] < N[ans.size() - 2]) ans[ans.size() - 1] = '9';
        }
        cout << "Case #" << i + 1 << ": " << ans << endl;
    }
    return 0;
}
