/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * calculate the area of a polygon based in shoelace
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

typedef pair<long long int, long long int> pii;
typedef vector<pii> vpii;

long long int cross_p(pii U, pii V)
{
    return (U.first * V.second) - (V.first * U.second); // determinant
}

long long int shoelace(vpii polygon)
{
    long long int area = 0;
    for (int i = 0; i < (int)polygon.size(); i++)
    {
        area += cross_p(polygon[i], polygon[(i - 1 + (int)polygon.size()) % (int)polygon.size()]);
    }
    return abs(area);
}

int main(int argc, char const *argv[])
{
    int total;
    cin >> total;
    long long int X, Y;
    vpii polygon;
    for (int i = 0; i < total; i++)
    {
        cin >> X;
        cin >> Y;
        polygon.push_back(make_pair(X, Y));
    }

    cout << shoelace(polygon);

    return 0;
}
