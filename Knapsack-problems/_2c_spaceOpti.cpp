#include <iostream>
#include <vector>
using namespace std;

int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<int> prev (x + 1);
    
//     base cases : 
    for(int j=0;j<= x;j++)
    {
        if(j % num[0] == 0)
        {
            prev[j] = j/num[0];
        }
        else 
            prev[j] = INT_MAX - 1;
    }
    for(int i=1;i<n;i++)
    {
        vector<int> curr(x + 1);
        for(int j=0;j<=x;j++)
        {
            int take = INT_MAX - 1;
            int notTake = prev[j];
            if(num[i] <= j)
            {
                take = 1 + curr[j - num[i]];
            }
            curr[j] = min(take, notTake);
        }
        prev = curr;
    }
    return (prev[x] == INT_MAX - 1 ? -1 : prev[x]);
}