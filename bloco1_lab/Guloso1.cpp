/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * find nearest age marriage for each man with olders priority
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    vector<int> man, woman;
    int reader, m_size, w_size, counter = 1;
    cin >> m_size >> w_size;
    while (!(m_size == 0 && m_size == 0))
    {
        for (int i = 0; i < m_size; i++)
        {
            cin >> reader;
            man.push_back(reader);
        }
        for (int i = 0; i < w_size; i++)
        {
            cin >> reader;
            woman.push_back(reader);
        }
        sort(man.begin(), man.end());
        sort(woman.begin(), woman.end());


        int prev_woman, cur_woman;
        prev_woman = woman.back();
        woman.pop_back();
        while (woman.size() > 0)
        {
            if (man.size() == 0)
            {
                break;
            }
            
            cur_woman =  woman.back();
            woman.pop_back();
            if (abs(man.back() - cur_woman) >= abs(man.back() - prev_woman))
            {
                prev_woman = cur_woman;
            }
            man.pop_back();
        }
        if(man.size() > 0)
            man.pop_back();
        if (man.size() != 0)
            printf("Case %d: %d %d\n", counter, (int)man.size(), man[0]);
        else
            printf("Case %d: 0\n", counter);
        
        cin >> m_size >> w_size;
        man.clear();
        woman.clear();
        counter++;
    }
    
    return 0;
}
