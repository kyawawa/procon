# ABC002
## C
std::cout だと少数の桁が勝手に丸め込まれたりして，うまくいかなかった(1707817/2.0あたりで確認)

presisionで有効桁数の設定が出来，ios::fixedやios::scientificで小数点以下の桁数の指定とできる
```c++
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    const double pi10 = M_PI * 100000.0;
    const double pi01 = M_PI * 0.00001;
    cout << "[1] Default" << endl;
    cout << pi10 << endl << pi01 << endl;
    cout << "[2] Precision(5)" << endl;
    cout.precision(5);
    cout << pi10 << endl << pi01 << endl;
    cout << "[3] ios::fixed" << endl;
    cout.setf(ios::fixed);
    cout << pi10 << endl << pi01 << endl;
    cout << "[4] ios::scientific" << endl;
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific);
    cout << pi10 << endl << pi01 << endl;
    cout << "[5] ios::fixed, ios::scientific" << endl;
    cout.setf(ios::fixed);
    cout << pi10 << endl << pi01 << endl;
    return 0;
}
```
出力結果
```
[1] Default
314159
3.14159e-05
[2] Precision(5)
3.1416e+05
3.1416e-05
[3] ios::fixed
314159.26536
0.00003
[4] ios::scientific
3.14159e+05
3.14159e-05
[5] ios::fixed, ios::scientific
3.1416e+05
3.1416e-05
```
