/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 *
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 5010;

int dp[MAXN][MAXN];
//  dp[i][j] armazena custo de transformar a substring w1[0:i] em w2[0:j]

int main(int argc, char const *argv[])
{    
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string w1, w2;
    cin >> w1 >> w2;

    int n = (int) w1.size();
    int m = (int) w2.size();

    for(int i = 1; i <= n; i++)
        dp[i][0] = i;
    for(int j = 1; j <= m; j++)
        dp[0][j] = j;

    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= m; j++)
        {
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;
            if(w1[i - 1] == w2[j - 1])
                dp[i][j] = min(dp[i][j], dp[i - 1][j - 1]);
        }

    cout << dp[n][m] << "\n";

    return 0;

}
