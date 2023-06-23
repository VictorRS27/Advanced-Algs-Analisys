#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> dp(x + 1, 0), h(n), s(n);
    for(int i = 0; i < n; i++)
        cin >> h[i];
    
    for(int i = 0; i < n; i++)
        cin >> s[i];

    for(int i = 0; i < n; i++)
        for(int j = x; j >= h[i]; j--)
            dp[j] = max(dp[j], dp[j - h[i]] + s[i]);

    int ans = 0;
    for(int i = 0; i <= x; i++)
        ans = max(ans, dp[i]);

    cout << ans << "\n";

    return 0;
}
