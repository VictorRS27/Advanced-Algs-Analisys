/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * StabMatch Algorithm
 *  */

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <math.h>
using namespace std;

double grass_size, grass_large;

pair<double, double> true_values(int center, int radius)
{
    double true_start, true_end, delta;
    delta = sqrt(pow(radius, 2) - pow(grass_large / 2, 2));
    true_start = center - delta;
    true_end = center + delta;
    return std::make_pair(true_start, true_end);
}

int main(int argc, char const *argv[])
{
    int total_sprinklers;
    while (cin >> total_sprinklers)
    {
        cin >> grass_size;
        cin >> grass_large;
        vector<pair<double, double>> sprinklers;
        for (int i = 0; i < total_sprinklers; i++)
        {
            int center, radius;
            cin >> center;
            cin >> radius;
            if (radius >= grass_large / 2)
            {

                sprinklers.push_back(true_values(center, radius));
            }
            else
            {
                total_sprinklers--;
                i--;
            }
        }
        sort(sprinklers.begin(), sprinklers.end());

        int used_sprinklers = 0;
        double covered = 0, larger = 0;
        for (int i = 0; i < total_sprinklers; i++)
        {

            if (sprinklers[i].first <= covered)
            {
                if (sprinklers[i].second > larger)
                {
                    larger = sprinklers[i].second;
                }
                if (i == total_sprinklers - 1)
                {
                    used_sprinklers++;
                    covered = larger;
                    if (covered < grass_size)
                    {
                        used_sprinklers = -1;
                        break;
                    }
                    break;
                }
            }
            else
            {
                used_sprinklers++;
                covered = larger;
                if (larger == 0)
                {
                    used_sprinklers = -1;
                    break;
                }
                if (covered >= grass_size)
                {
                    break;
                }
                larger = 0;
                i--;
            }
        }
        if (total_sprinklers == 0)
        {
            used_sprinklers = -1;
        }
        
        cout << used_sprinklers << "\n";
    }

    return 0;
}
