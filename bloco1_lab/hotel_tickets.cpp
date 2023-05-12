/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * show the maximus number possible making K swaps from other number
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int x, y, z;
vector<long long int> dp_optmal, days;

long long int calculator(char type, int day)
{
    int k = day;

    switch (type)
    {
    case 'x':
        if (day != 0)
        {
            return x + dp_optmal[day - 1];
        }
        else
        {
            return x;
        }
        break;

    case 'y':
        while (k >= 0 && days[k] >= days[day] - 7)
        {
            k--;
        }
        if (k >= 0)
        {
            return dp_optmal[k] + y;
        }
        if (k == -1)
        {
            return y;
        }
        break;

    case 'z':
        while (k >= 0 && days[k] >= days[day] - 30)
        {
            //cout << days[k] << " " << day << " " << k << "\n";
            k--;
        }
        if (k >= 0)
        {
            return dp_optmal[k] + z;
        }
        if (k == -1)
        {
            return z;
        }
        
        break;
    default:
        break;
    }
    //cout << "imprevisto";
    return 10000000;
}

int main(int argc, char const *argv[])
{
    int total_days;
    long long int buying_x, buying_y, buying_z;
    cin >> total_days;
    cin >> x;
    cin >> y;
    cin >> z;
    for (int i = 0; i < total_days; i++)
    {
        int in;
        cin >> in;
        days.push_back(in);
        buying_x = calculator('x', i);
        buying_y = calculator('y', i);
        buying_z = calculator('z', i);

        //printf("%lld, %lld, %lld\n", buying_x, buying_y, buying_z);

        dp_optmal.push_back(min({buying_x, buying_y, buying_z}));
    }

    printf("%lld", dp_optmal.back());
    return 0;
}
