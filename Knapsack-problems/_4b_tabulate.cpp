#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &wt)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (w + 1, 0));
    for(int j=0;j<=w;j++)
    {
        if(wt[0] <= j)
            dp[0][j] = (j / wt[0]) * profit[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            int take = -1e9;
            int notTake = dp[i-1][j];
            if(wt[i] <= j)
                take = profit[i] + dp[i][j - wt[i]];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][w];
}
