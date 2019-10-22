#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
// #define int long long
#define N 510
#define mod 1000000007
int arr[N];
int dp[N][101] ={0};
int n;

void solve()
{
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] < arr[j])
            {

                for(int k = 1; k<=100; k++)
                {
                    if(dp[i][k])
                    {
                        dp[j][__gcd(k, arr[j])] = ( dp[i][k] + dp[j][__gcd(k, arr[j])] )%mod;
                    }
                }
            }
        }
    }
    int ans =0;
    for(int i=0; i<n; i++)
    {
        ans  = (ans + dp[i][1])%mod;
    }
    cout<<ans<<endl;

    return;

}

signed main()
{
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
        dp[i][arr[i]] ++;
    }

    solve();
    return 0;
}
