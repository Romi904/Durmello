#include <iostream>
#include <vector>
using namespace std;

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<int> prev(maxWeight + 1);
    
    for(int j = weight[0];j<=maxWeight;j++)
    {
        prev[j] = value[0];
    }
    
    prev[0] = 0;
    
    for(int i=1;i<n;i++)
    {
        vector<int> curr(maxWeight + 1);
        curr[0] = 0;
        for(int j=1;j<=maxWeight;j++)
        {
            int notTake = prev[j];
            int take = -1e9;
            if(weight[i] <= j)
                take = prev[j - weight[i]] + value[i];
            curr[j] = max(take, notTake);
        }
        prev = curr;
    }
    return prev[maxWeight];
}