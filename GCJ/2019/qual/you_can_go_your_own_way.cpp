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
    size_t T;
    cin >> T;

    unsigned int N;
    string path;

    for (size_t i = 0; i < T; ++i) {
        cin >> N;
        cin >> path;

        // print answer
        cout << "Case #" << i + 1 << ": ";
        for (auto itr = path.begin(); itr != path.end(); ++itr) {
            cout << ((*itr == 'E') ? 'S' : 'E');
        }
        cout << endl;
    }
    return 0;
}
