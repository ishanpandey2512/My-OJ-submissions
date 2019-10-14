    #include <bits/stdc++.h>
    using namespace std;
    #define N 1005
    signed main() 
    {
        //precalculate
        int f[N]={0};
        int g[N]={0};
        int h[N]={0};
        
        //base cases
        f[0]=1, f[1]=1;
        g[0]=1, g[1]=2;
        h[0]=1, h[1]=1;
        
        for(int i=2; i<N; i++)
        {
            f[i] = (i-2>=0?f[i-2]:0) + (i-1>=0?f[i-1]:0) + 2*(i-2>=0?g[i-2]:0) + (i-2>=0?h[i-2]:0);
            g[i] = f[i] + (i-1>=0?g[i-1]:0);
            h[i] = f[i] + (i-2>=0?h[i-2]:0);
            
        }
        
    	int n;long cas;
    	cin>>n;
    	
    	cas=1;
    	int x;
    	while(n--)
    	{
    	    cin>>x;
    	    cout<<cas<<" "<<f[x]<<endl;
    	    cas++;
    	}
    	return 0;
    }
