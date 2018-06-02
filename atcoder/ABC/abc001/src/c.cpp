#include<iostream>
using namespace std;

int main()
{
    int deg, w;
    double dis;
    string dir;
    string dir_list[16] = {"N", "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE",
                           "S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"};

    cin >> deg >> dis;
    dis /= 6.0;
    if (dis < 2.5) w = 0;
    else if (dis < 15.5) w = 1;
    else if (dis < 33.5) w = 2;
    else if (dis < 54.5) w = 3;
    else if (dis < 79.5) w = 4;
    else if (dis < 107.5) w = 5;
    else if (dis < 138.5) w = 6;
    else if (dis < 171.5) w = 7;
    else if (dis < 207.5) w = 8;
    else if (dis < 244.5) w = 9;
    else if (dis < 284.5) w = 10;
    else if (dis < 326.5) w = 11;
    else w = 12;

    deg += 3600 / 32;
    deg %= 3600;
    if (w == 0) dir = "C";
    else dir = dir_list[deg / 225];

    cout << dir << " " << w << endl;
    return 0;
}
