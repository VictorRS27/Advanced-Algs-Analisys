/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * find the combination of coins that equals a value, but with the minimus total of coins
 *
 *  */

#include <bits/stdc++.h>
using namespace std;


int calculate(int *pd, vector<int> &coins, int total_value, int cur_value, int cur_count) {
    if (pd[cur_value] != 0)
    {
        return pd[cur_value];
    }
    int min_count = 1005;
    for (auto i = (int) coins.size()-1; i >= 0; i--)
    {
        if (cur_value + coins[i] == total_value)
        {
            return cur_count;
        } else if (cur_value + coins[i] < total_value) {
            min_count = min( calculate(pd, coins, total_value, cur_value + coins[i], cur_count+1), min_count);
        }
        
    }
    pd[cur_value] = min_count;
    return min_count;
    
}


int main(int argc, char const *argv[])
{
    int testcases;
    cin >> testcases;
    for (int i = 0; i < testcases; i++)
    {
        int value, total_coins;
        cin >> value; 
        vector<int> coin_values;
        cin >> total_coins;
        for (int i = 0; i < total_coins; i++)
        {
            int tmp;
            cin >> tmp;
            coin_values.push_back(tmp);
        }
        
        int pd[value] = {0};

        int to_exit = calculate(pd, coin_values, value, 0, 1);
        cout << to_exit << endl;
    }
    
    return 0;
}
