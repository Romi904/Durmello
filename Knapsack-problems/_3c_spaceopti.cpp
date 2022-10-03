#include <iostream>
#include <vector>
using namespace std;

int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0);
//         base case:
        for(int j=0;j<=amount;j++)
        {
            if(j % coins[0] == 0)
                prev[j] = 1;
        }
        for(int i=1;i<n;i++)
        {
            vector<int> curr(amount + 1, 0);
            for(int j=0;j<=amount;j++)
            {
                int take = 0;
                int notTake = prev[j];
                if(coins[i] <= j)
                    take = curr[j - coins[i]];
                curr[j] = take + notTake;
            }
            prev = curr;
        }
        return prev[amount];
    }