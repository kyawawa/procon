#include <iostream>
#include <string>
using namespace std;

int main()
{
    string x;
    cin >> x;
    for (int i = 0; i < x.size(); ++i) {
        if (x[i] == 'a' || x[i] == 'i' || x[i] == 'u' || x[i] == 'e' || x[i] == 'o') continue;
        cout << x[i];
    }
    cout << endl;
    return 0;
}
