#include <iostream>
#include <vector>
using namespace std;

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &wt)
{
    // Write Your Code Here.
    vector<int>prev (w + 1, 0);
    for(int j=0;j<=w;j++)
    {
        if(wt[0] <= j)
            prev[j] = (j / wt[0]) * profit[0];
    }
    for(int i=1;i<n;i++)
    {
        vector<int> curr(w + 1, 0);
        for(int j=0;j<=w;j++)
        {
            int take = -1e9;
            int notTake = prev[j];
            if(wt[i] <= j)
                take = profit[i] + curr[j - wt[i]];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[w];
}
