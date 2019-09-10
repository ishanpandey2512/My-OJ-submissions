#include<bits/stdc++.h>
#include<queue>

using namespace std;

//all possible moves of a knight from a position
int x[10] = {0,-1,-1,-2,-2,2,2,1,1};
int y[10] = {0,-2,2,-1,1,-1,1,-2,2};

//always declare auxilairy arrays outside bfs to prevent from segmentation errors
int vis[8][8];
int moves[8][8];

int bfs(int x1, int y1, int x2, int y2)
{
    // 8*8 chessboard numbered from 1 to 8
    
    memset(vis, 0, sizeof vis);
    // moves taken to reach a to a cell[i, j] from source
    
    memset(moves, 0, sizeof moves);
    
    queue<pair<int, int>> q; //stores cells acc to bfs
    
    pair<int, int> p1;
    p1.first = x1;
    p1.second = y1;
    
    q.push(p1);//source pushed into queue
    vis[x1][y1] = true;
    
    //bfs start
    while(!q.empty())
    {
        p1 = q.front();
        q.pop();
        
        //Base Case to check destination
        if(p1.first == x2 and p1.second == y2)
        {
            return moves[x2][y2];
            
        }
        
        for(int i=1; i<=8; i++)//to scratch among possible moves prestored in x and y array
        {
            int m = p1.first + x[i]; //x coord of next possible
            int n = p1.second + y[i]; //y coord
            
            //edge cases
            if(m>8 or m<1 or n>8 or n<1)
                continue; //then we wont do bfs we simply pass
                
            else
            {
                vis[m][n] = true;
                //update moves
                moves[m][n] = moves[p1.first][p1.second] + 1;
                q.push(make_pair(m, n));
                
            }
        }
        
        
    }
  
    
}

signed main()
{
    
    
    int t;
    cin>>t;
    while(t--)
    {   
        char x1, x2;
        int y1, y2;
        cin>>x1>>y1>>x2>>y2;
         
        cout<<bfs(x1 - 'a' +1, y1, x2 - 'a' + 1, y2)<<endl;
       
       
    }


    return 0;
}
