#include<bits/stdc++.h>
using namespace std;

//cn way

int min(int a, int b){
    if(a>b)
        return b;
    else    
        return a;
}


int findMaxSquareWithAllZeros(int** arr, int row, int col){
    int dp[row][col];
    
    for(int i=0;i<row;i++){
        dp[i][0] = 1-arr[i][0];
    }
    for(int j=0;j<col;j++){
        dp[0][j] = 1-arr[0][j];
    }
    
    for(int i=1;i<row;i++){
        for(int j=1;j<col;j++){
            if(arr[i][j])
                dp[i][j] = 0;
            else
                dp[i][j] = min(dp[i-1][j], min(dp[i-1][j-1], dp[i][j-1])) + 1;
        }
    }
    
    int m = -1;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if(dp[i][j] > m)
                m = dp[i][j];
        }
    }
    
    return m;
    
}

//way 2

int calSquare(int **arr,int m,int n)
{
    int **dp=new int*[m];
    for(int i=0;i<m;i++)
        dp[i]=new int[n];

    for(int i=0;i<n;i++)
    {
        if(arr[0][i]==1)
        dp[0][i]=1;
        else
        dp[0][i]=0;
    }

 for(int i=1;i<m;i++)
 {
     if(arr[i][0]==1)
     dp[i][0]=1;
     else
     dp[i][0]=0;
 }

 for(int i=1;i<m;i++)
 {
     for(int j=1;j<n;j++)
     {
         if(arr[i][j]==1)
         dp[i][j]=min((dp[i-1][j-1]),min(dp[i-1][j],dp[i][j-1]))+1;
         else
         dp[i][j]=0;
     }

 }

 int MAX_ELE=0;
 for(int i=0;i<m;i++)
 {
     for(int j=0;j<n;j++)
     {
         if(dp[i][j]>=MAX_ELE)
         MAX_ELE=dp[i][j];
     }
 }

 return MAX_ELE;
}


int main()
{
    int t;
   cin>>t;
   while(t-->0)
   {
       int n,m;
       cin>>m>>n;
       int **input=new int *[m];
       for(int i=0;i<m;i++)
         input[i]=new int[n];

        for(int i=0;i<m;i++)
       {
        for(int j=0;j<n;j++)
        {
            cin>>input[i][j];
        }
       }
       int ans=calSquare(input,m,n);
       cout<<ans<<endl;
   }
   return 0;
}
