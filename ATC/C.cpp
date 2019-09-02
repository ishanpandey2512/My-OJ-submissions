#include<bits/stdc++.h>
using namespace std;
#define v_int vector<int> 

//Recursive Approach:

const int NO_OF_TYPES = 3;
//marking choices here so that its easy to understand
// 0 means swim today
// 1 means catch today
// 2 means doHW today

signed main()
{
    int n;
    cin>>n; // no of days

    v_int swimH(n+1);
    v_int catchH(n+1);
    v_int dohwH(n+1);

    for(int i=1; i<=n; i++)
    {
        scanf("%d%d%d", &swimH[i], &catchH[i], &dohwH[i]);
    }

    //we want to calculate maxm happiness 
    vector<v_int> maxm_happiness( n+1, v_int(NO_OF_TYPES, 0) ); //n+1 * 3 size initialized with 0

    for(int i=1; i<=n; i++)
    {
        //if on ith day I chose swimming
        maxm_happiness[i][0] = swimH[i] + max( maxm_happiness[i-1][1] , maxm_happiness[i-1][2] );

        //if on the ith day I chose catching
        maxm_happiness[i][1] = catchH[i] + max( maxm_happiness[i-1][0] , maxm_happiness[i-1][2] );

        //if on the ith day I chose to do HW
        maxm_happiness[i][2] = dohwH[i] + max( maxm_happiness[i-1][0] , maxm_happiness[i-1][1] );

    }

    //ans will max value of maxm_happiness[n][k] where k =0, 1, 2 i.e. last day of any of three choices
    int ans = max({ maxm_happiness[n][0], maxm_happiness[n][1], maxm_happiness[n][2] });

    cout<<ans;



    return 0;
}

//ITERATIVE:
int main()
{
    int n;
    scanf("%d", &n);
    vector<int> dp(3);
    // dp[i] - the total cost such that we did activity i on the last considered day
    for(int day = 0; day < n; ++day) 
    {
        vector<int> new_dp(3, 0); //final result till this day i is stored in this from previous dp table, later dp is updated with new_dp
        vector<int> c(3);   // cost of all three activities this day

        for(int i = 0; i < 3; ++i) 
        {
            scanf("%d", &c[i]);
        }

        // int a, b, c - a lot of implementation
        for(int i = 0; i < 3; ++i) 
        //i represents dp state from previous day: activity chosen from previous day
        {
            for(int j = 0; j < 3; ++j) // activity present day
            {
                if(i != j) //obviously activity from present day != activity past day
                {
                    new_dp[j] = max(new_dp[j], dp[i] + c[j]);
                }
            }
        }
        dp = new_dp;// reassign states for next iteration, it will become past day
    }
    printf("%d\n", max({dp[0], dp[1], dp[2]}));
}


