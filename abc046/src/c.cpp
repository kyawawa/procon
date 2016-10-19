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

    int n;
    cin >> n;
    vector<int> t(n), a(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> a[i];
    }

    long long int ts = t[0];
    long long int as = a[0];
    // cout << "ts:as : " << ts << " : " << as << endl;

    long long int ratio;
    for (int i = 1; i < n; i++) {
        if (t[i] >= ts && a[i] >= as) {
            ts = t[i];
            as = a[i];
        } else {
            // ratio = ((double)ts / t[i] > (double)as / a[i]) ? (long long int)ceil((double)ts / t[i]) : (long long int)ceil((double)as / a[i]);
            ratio = max((ts % t[i] == 0) ? ts / t[i] : ts / t[i] + 1,
                        (as % a[i] == 0) ? as / a[i] : as / a[i] + 1);
            ts = t[i] * ratio;
            as = a[i] * ratio;
        }
        // cout << "ts:as : " << ts << " : " << as << endl;
    }

    cout << ts + as << endl;

    return 0;
}
