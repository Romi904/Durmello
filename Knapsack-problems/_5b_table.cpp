#include <iostream>
#include <vector>
using namespace std;

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int> > dp(n, vector<int> (n + 1));
    
    for(int j=0;j<=n;j++)
    {
        dp[0][j] = j * price[0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            int take = INT_MIN;
            int notTake = 0 + dp[i-1][j];
            int len = i + 1;
            if(len <= j)
            {
                take = price[i] + dp[i][j - len];
            }
            dp[i][j] = max(take, notTake);
        }
    }
    return dp[n-1][n];
}
