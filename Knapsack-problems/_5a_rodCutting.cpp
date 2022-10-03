#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &price, int i, int n, vector<vector<int> > &dp)
{
    if(i == 0)
    {
        return n * price[0];
    }
    
    if(dp[i][n] != -1)
        return dp[i][n];
    
    int take =INT_MIN;
    
    int notTake = 0 + solve(price, i - 1, n, dp);
    int len = i + 1;
    if(len <= n)
    {
        take = price[i] + solve(price, i, n - len, dp);
    }
    return dp[i][n] = max(take, notTake);
}

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int> > dp(n, vector<int> (n + 1, -1));
    return solve(price, n-1, n, dp);
}
