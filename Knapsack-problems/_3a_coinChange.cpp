#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &coins, int i, int val, vector<vector<int> > &dp)
    {
        if(i == 0)
        {
            return (val % coins[0] == 0);
        }
        
        if(dp[i][val] != -1)
            return dp[i][val];
        
        int take = 0;
        int notTake = solve(coins, i - 1, val, dp);
        if(coins[i] <= val)
            take = solve(coins, i, val - coins[i], dp);
        
        return dp[i][val] = take + notTake;
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int> > dp(n, vector<int> (amount + 1, -1));
        return solve(coins, n - 1, amount, dp);
    }