#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double s;
    s = ((c - a) * (f - b) - (d - b) * (e - a)) / 2.0;
    // cout << s > 0 ? s : -s << endl;
    printf("%.1f\n", s > 0 ? s : -s);
    return 0;
}
