#include<bits/stdc++.h>
using namespace std;

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
