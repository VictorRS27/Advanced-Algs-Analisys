/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * show the maximus number possible making K swaps from other number
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int vec_size, total_querys;
    vector<int> vec;
    cin >> vec_size;
    for (int i = 0; i < vec_size; i++)
    {
        int x;
        cin >> x;
        vec.push_back(x);
    }

    vector<vector<int>> lookup;
    vector<int> lookup_line;
    for (int i = 0; i < vec_size; i++)
    {
        for (int j = i; j < vec_size; j++)
        {
            if (j == i)
            {
                lookup_line.push_back(i);
            } else {
                lookup_line.push_back((vec[lookup_line[j-i-1]]<=vec[j])?lookup_line[j-i-1]:j);
            }
        }
        lookup.push_back(lookup_line);
        lookup_line.clear();
    }

    cin >> total_querys;
    for (int i = 0; i < total_querys; i++)
    {
        int sta, end_i;
        cin >> sta >> end_i;
        cout << vec[lookup[sta][end_i-sta]] << endl;
    }
    
    return 0;
}
