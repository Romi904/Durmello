// Given an integer array of coins[ ] of size N representing different types of currency and an integer sum, The task is to find the number of ways to make sum by using different combinations from coins[].  

// Note: Assume that you have an infinite supply of each type of coin. 

#include <bits/stdc++.h>
using namespace std;

int coinchange(vector<int>& a, int v, int n, vector<vector<int> >& dp) {
    if (v == 0)
        return dp[n][v] = 1;
    if (n == 0)
        return 0;
    if (dp[n][v] != -1)
        return dp[n][v];
    if (a[n - 1] <= v) {
        return dp[n][v] = coinchange(a, v - a[n - 1], n, dp) + coinchange(a, v, n - 1, dp);
    } else 
        return dp[n][v] = coinchange(a, v, n - 1, dp);
}

int main() {
    int tc = 1;
    while (tc--) {
        int n, v;
        n = 3, v = 4;
        vector<int> a = {1, 2, 3};
        vector<vector<int> > dp(n + 1, vector<int>(v + 1, -1));
        int res = coinchange(a, v, n, dp);
        cout << res << endl;
    }
}
