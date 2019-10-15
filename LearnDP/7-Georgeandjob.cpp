#include <bits/stdc++.h>
#define newline ("\n")
#define int long long
#define MOD 1000000007
using namespace std;
 
int dp[10000000];
 
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
 
    int n, m, k;
    cin >> n >> m >> k;
    long long arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    long long cum[n + 1];
    cum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cum[i] = arr[i - 1] + cum[i - 1];
    }
    long long dp[k + 1][n + 1];
    memset(dp, 0ll, sizeof(dp));
    for (int i = 1; i <= k; i++)
    {
        for (int j = i * m; j <= n; j++)
        {
            if (i == 1)
            {
                dp[i][j] = max(dp[i][j - 1], cum[j] - cum[j - m]);
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + cum[j] - cum[j - m]);
            }
        }
    }
    cout << dp[k][n];
    return 0;
}
