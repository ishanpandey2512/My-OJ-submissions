#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
const int N = 300000;

int height[N];
int dp[N];
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);

signed main()
{
    IOS
    int n;
    cin>>n;
    //0-based
    for(int i=0; i<n; i++)
    {
        cin>>height[i];
        dp[i] = (1LL << 60LL);
    }
    
    // for(int i=0; i<n; i++)
    // {
    // cout<<dp[i]<<endl;
    // }

    //for the first house, no previous jumps possible
    dp[0] = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=1; i-j >= 0; j<<=1) //j = j*2
        //from ith position, move j positions left and calc, if its possible to jump from i-j to i
        {
            dp[i] = min(dp[i], dp[i-j] + abs(height[i] - height[i-j]));
        }
    }
    
    cout<<dp[n-1]<<endl;
    
    // for(int i=0; i<n; i++)
    // {
    // cout<<dp[i]<<endl;
    // }

    return 0;
}
