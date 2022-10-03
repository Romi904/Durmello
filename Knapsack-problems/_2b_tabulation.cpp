#include <iostream>
#include <vector>
using namespace std;

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int> > dp(n, vector<int> (x + 1));
    
//     base cases : 
    for(int j=0;j<= x;j++)
    {
        if(j % num[0] == 0)
        {
            dp[0][j] = j/num[0];
        }
        else 
            dp[0][j] = INT_MAX - 1;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=x;j++)
        {
            int take = INT_MAX - 1;
            int notTake = dp[i-1][j];
            if(num[i] <= j)
            {
                take = 1 + dp[i][j - num[i]];
            }
            dp[i][j] = min(take, notTake);
        }
    }
    return (dp[n-1][x] == INT_MAX - 1 ? -1 : dp[n-1][x]);
}