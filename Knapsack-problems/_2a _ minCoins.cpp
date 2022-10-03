#include <iostream>
#include <vector>
using namespace std;

int solve(vector<int> &nums, int i, int x, vector<vector<int> > &dp)
{
    if(i == 0)
    {
        if(x % nums[0] != 0)
            return INT_MAX - 1;
        return x / nums[0];
    }
    
    if(dp[i][x] != -1)
        return dp[i][x];
    
    int pick = INT_MAX - 1;
    int notPick = 0 + solve(nums, i - 1, x, dp);
    if(nums[i] <= x)
    {
        pick = 1 + solve(nums, i, x - nums[i], dp);
    }
    return dp[i][x] = min(pick, notPick);
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int> > dp(n, vector<int> (x + 1, -1));
    return (solve(num, n-1, x, dp) == INT_MAX - 1 ? -1 : solve(num, n-1, x, dp));
}