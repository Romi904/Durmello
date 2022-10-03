#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int> > dp(n, vector<int> (maxWeight + 1));
    
    for(int i=0;i<n;i++)
    {
        dp[i][0] = 0;
    }
    for(int j = weight[0];j<=maxWeight;j++)
    {
        dp[0][j] = value[0];
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<=maxWeight;j++)
        {
            int notTake = dp[i-1][j];
            int take = -1e9;
            if(weight[i] <= j)
                take = dp[i-1][j - weight[i]] + value[i];
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][maxWeight];
}