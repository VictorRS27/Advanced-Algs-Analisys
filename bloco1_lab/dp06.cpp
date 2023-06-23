/*
 * Victor Rodrigues da Silva  NUSP: 12566140
 *
 *
 *
 *  */

#include <bits/stdc++.h>
using namespace std;

string LCS(const std::string& str1, const std::string& str2) {
    int m = str1.length();
    int n = str2.length();

    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Preenche a tabela dp com os comprimentos das subsequências comuns
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Constrói a subsequência comum a partir da tabela dp
    std::string lcsString;
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (str1[i - 1] == str2[j - 1]) {
            lcsString.push_back(str1[i - 1]);
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1]) {
            i--;
        } else {
            j--;
        }
    }

    // Inverte a string resultante, pois foi construída de trás para frente
    std::reverse(lcsString.begin(), lcsString.end());

    return lcsString;
}

int main(int argc, char const *argv[])
{
    string w1, w2;
    cin >> w1 >> w2;
    cout << LCS(w1, w2) << endl;
    return 0;
}
