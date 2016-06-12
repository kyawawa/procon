#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string d = "WWBWBWW"; // Si
    size_t pos = s.find(d);
    string ans;
    switch (pos) {
    case 0:
        ans = "Si";
        break;
    case 2:
        ans = "La";
        break;
    case 4:
        ans = "So";
        break;
    case 6:
        ans = "Fa";
        break;
    case 7:
        ans = "Mi";
        break;
    case 9:
        ans = "Re";
        break;
    case 11:
        ans = "Do";
        break;
    }
    cout << ans << endl;
    return 0;
}
