#include<bits/stdc++.h>
using namespace std;
// #define int long long
#define ll long long
#define endl "\n"
#define rep(i, n) for(int i=0; i<n; i++)
#define M 200005
#define pb push_back
vector<vector<int>> adj;
//if given graph is a tree, then vertex cover is possible using dp, otherwise it is NPHARD problem.
int dp[M][2];

void dfs(int root, int par=-1)
{
    //two options : to include this node in vertex cover, dont include this node rather include its children
    int included = 1;
    int not_included = 0;

    //F(u,1) = Currently we're in 'u' node and there is a watchman in this node.
    //F(u,0) = Currently we're in 'u' node and there is no watchman in this node.

    for(auto i: adj[root])
    {
        if(i == par) //cycle detected
            continue;

        dfs(i, root);

        included += min(dp[i][0], dp[i][1]);
        not_included += dp[i][0];

    }

    dp[root][0] = included;
    dp[root][1] = not_included;
}

signed main()
{
    int n;
    cin>>n;
    adj.resize(n+1);
    //n-1 edges input
    for(int i=1; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }

    int root=-1;
    for(int i=1; i<=n; i++)
    {
        if((int)adj[i].size() == 1) //if it has only 1 edge,(like in leaf node) we make it root and do dfs
        {    root = i; break;}
    }

    dfs(root);

    cout << min(dp[root][0], dp[root][1]) << endl;
  
	return 0;
}
