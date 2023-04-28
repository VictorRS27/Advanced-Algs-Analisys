/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * show the maximus number possible making K swaps from other number
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int wors_size = 0;

int find_max_and_index(string original, int cur, int *last_max, int *max)
{
    if(cur >= wors_size) return 0;

    if (original[cur] > *max)
    {
        *max = original[cur];
        *last_max = cur;
    }
    if (original[cur] == *max)
    {
        *last_max = cur;
    }

    return find_max_and_index(original, cur+1, last_max, max);
}


int main(int argc, char const *argv[])
{
    string reader;
    while (cin >> reader)
    {
        wors_size = (int)reader.size();
        int k;
        cin >> k;
        for (int i = 1; i <= k; i++)
        {
            int max = -1, last_max = i;
            find_max_and_index(reader, i, &last_max, &max);
            if (reader[i-1] < max)
            {
                swap(reader[i-1], reader[last_max]);
            }            
        }
        cout << reader << endl;
    }
    
    return 0;
}
