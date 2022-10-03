#include <iostream>
#include <vector>
using namespace std;

int solve(int i, int w, vector<int> &profit, vector<int> &wt, vector<vector<int> > &dp)
{
    if(i == 0)
    {
        if(wt[0] <= w)
        {
            return (w / wt[0]) * profit[0];
        }
        return 0;
    }
    if(dp[i][w] != -1)
        return dp[i][w];
    
    int take = -1e9;
    int notTake = 0 + solve(i-1, w, profit, wt, dp);
    if(wt[i] <= w)
        take = profit[i] + solve(i, w - wt[i], profit, wt, dp);
    return dp[i][w] = max(take, notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int> (w + 1, -1));
    return solve(n - 1, w, profit, weight, dp);
}
