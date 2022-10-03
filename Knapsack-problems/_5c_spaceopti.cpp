#include <iostream>
#include <vector>
using namespace std;

int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<int> prev(n + 1);
    
    for(int j=0;j<=n;j++)
    {
        prev[j] = j * price[0];
    }
    
    for(int i=1;i<n;i++)
    {
        vector<int> curr(n + 1, 0);
        for(int j=0;j<=n;j++)
        {
            int take = INT_MIN;
            int notTake = 0 + prev[j];
            int len = i + 1;
            if(len <= j)
            {
                take = price[i] + curr[j - len];
            }
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[n];
}
