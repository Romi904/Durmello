#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &wt ,vector<int> &val, int i, int w, vector<vector<int> > &dp)
{
    if(i == 0)
    {
        if(wt[0] <= w)
            return val[0];
        
        return 0;
    }
    if(w == 0)
        return 0;
    
    if(dp[i][w]  != -1)
        return dp[i][w];
    
    int notTake = solve(wt, val, i - 1, w, dp) + 0;
    int take = -1e9;
    if(wt[i] <= w)
    {
        take = solve(wt, val, i - 1, w - wt[i], dp) + val[i];
    }
    return dp[i][w] = max(take, notTake);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int> > dp(n, vector<int> (maxWeight + 1, -1));
    return solve(weight, value, n-1, maxWeight, dp);
}