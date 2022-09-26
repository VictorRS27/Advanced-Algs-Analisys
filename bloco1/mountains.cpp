/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * Backtraking based in queens problem
 *
 * Optimized but c++ offensive.
 *  */
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    int total_mountains;
    int cur_one_step, cur_two_step;
    vector<int> dp_optmal, mountains;
    int x;
    cin >> total_mountains;
    cin >> x;
    mountains.push_back(x);
    dp_optmal.push_back(0);
    int y;
    cin >> y;
    mountains.push_back(y);
    dp_optmal.push_back(abs(x - y));
    for (int i = 2; i < total_mountains; i++)
    {
        cin >> x;
        mountains.push_back(x);
        cur_one_step = dp_optmal[i - 1] + abs(mountains[i - 1] - mountains[i]);
        cur_two_step = dp_optmal[i - 2] + abs(mountains[i - 2] - mountains[i]);

        // printf("[%d %d]", cur_one_step, cur_two_step);
        dp_optmal.push_back(min(cur_one_step, cur_two_step));
    }

    printf("%d", dp_optmal.back());
    return 0;
}
