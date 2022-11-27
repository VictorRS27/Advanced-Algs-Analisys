/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 * determinate how pieces take to get a winner state
 *
 *  */

#include <bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    int total_cases;
    cin >> total_cases;

    for (int i = 0; i < total_cases; i++)
    {
        int piles, summon_xor = 0;
        cin >> piles;
        int board[piles];
        for (int j = 0; j < piles; j++)
        {
            cin >> board[j];
            summon_xor = summon_xor ^ board[j];
        }
        
        if (summon_xor == 0)
        {
            /* for (int j = 0; j < piles; j++)
            {
                if (summon_xor ^ board[j] < board[j])
                {
                    if (board[j] - (summon_xor ^ board[j]) != 1)
                    {
                        cout << 1 << "\n";
                    } else
                    {
                        cout << 2 << "\n";
                    }
                    
                    
                }
                
            } */
            cout << 1 << "\n";
        }
        else
        {
            cout <<  0 << "\n";
        }
        
        
    }
    
    return 0;
}
