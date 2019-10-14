        #include <stdio.h>
        int main() 
        {
        	int n, T[31], F[31];
        	T[0]=1; F[0]=0;
        	//memoise the values first
        	for(int i=1; i<=30; i++)
        	{
        		T[i] = ((i>=2)?3*T[i-2]:0) + ((i>=3)?2*F[i-3]:0);
        		
        		F[i] = T[i-1] + ((i>=2)?F[i-2]:0);
        	}
        	while(true)
        	{
        		scanf("%d",&n);
        		if(n==-1) break;
        		printf("%d\n",T[n]);
        	}
        	return 0;
        } 
