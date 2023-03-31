/*
 * Victor Rodrigues da Silva
 *
 * UVa 12100
 *
 * achar a mediana
 */

#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

int main(int argc, char const *argv[])
{
    vector<lli> elements; 
    int reader;
    cin >> reader;
    do
    {
        elements.push_back(reader);
        nth_element(elements.begin(), elements.begin() + (int)elements.size()/2, elements.end());
        int tmp = elements[(int)elements.size()/2];
        printf("%d\n", tmp);

        if (!(cin >> reader)) break;

        elements.push_back(reader);
        int median;
        if (reader > tmp)
        {
            nth_element(elements.begin(), elements.begin() + (int)elements.size()/2, elements.end());
            median  = (elements[(int)elements.size()/2] + tmp) /2;
        }
        else if (reader < tmp)
        {
            nth_element(elements.begin(), elements.begin() + (int)elements.size()/2-1, elements.end());
            median  = (elements[(int)elements.size()/2-1] + tmp) /2;
        }
        
        printf("%d\n", median);
        
        
    } while (cin >> reader);

    return 0;
}
