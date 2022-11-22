/*
 * Victor Rofrigues da Silva  NUSP: 12566140
 *
 * LIS (Longest Common Subsequence)
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 2010

int dp[MAX_SIZE][MAX_SIZE];

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    
    while(t--)
    {

        string word1, word2;
        cin >> word1 >> word2;

        int word_size1 = (int) word1.size();
        int word_size2 = (int) word2.size();

        for(int i = 0; i <= word_size1; i++)
            dp[i][0] = i;

        for(int j = 0; j <= word_size2; j++)
            dp[0][j] = j;


        for (int i = 1; i <= word_size1; i++)
        {
            for (int j = 1; j <= word_size2; j++)
            {
                if (word1[i-1] != word2[j-1])
                {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
                }else
                {
                    dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1]));
                }
                
            }
        }

        cout << dp[word_size1][word_size2] << "\n";

    }

    return 0;
}
