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

    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    const int idx = K - 1;
    switch(S[idx]) {
      case 'A':
          S[idx] = 'a';
          break;
      case 'B':
          S[idx] = 'b';
          break;
      default:
          S[idx] = 'c';
          break;
    }

    cout << S << endl;
    return 0;
}
