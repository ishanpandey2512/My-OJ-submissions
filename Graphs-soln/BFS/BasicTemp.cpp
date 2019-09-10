#include<bits/stdc++.h>
using namespace std;
//BFS: used to find shortest path (containing minm of edges) from source to a vertex in a unweighted graph


vector<vector<int>> adj; //adj.list
int n; //no of vertices
int src; //source vertex

queue<int> q;  
vector<int> vis(n); //used status
vector<int> dis(n), par(n);  //distance from source vertex, parent vertex of ith vertex


void bfs()
{
    q.push(src);
    vis[src] = true;
    par[src] = -1;

    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        for(int u: adj[v])
        {
            if(!vis[u])
            {
                vis[u] = true; //fire spread
                q.push(u);
                dis[u] = dis[v] + 1;
                par[u] = v;
            }
        }
    }
}


signed main()
{

}

