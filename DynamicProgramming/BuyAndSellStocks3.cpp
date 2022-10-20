// 123. Best Time to Buy and Sell Stock III
/*  You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete at most two transactions.

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/
// RECURSION AND MEMOIZATION
class Solution {
public:
    int memo(int inx,int buyornot,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(inx==prices.size()) return 0;
        if(k==0) return 0; // no more transactions allowed
        if(dp[inx][buyornot][k]!=-1) return dp[inx][buyornot][k];
        if(buyornot==1){ // can buy 
           int buy=0-prices[inx]+memo(inx+1,0,k,prices,dp);
           int notbuy=memo(inx+1,1,k,prices,dp);
           return dp[inx][buyornot][k]=max(buy,notbuy);
        }
        else{ // can sell
           int sell=prices[inx]+memo(inx+1,1,k-1,prices,dp);
           int notsell=memo(inx+1,0,k,prices,dp);
           return dp[inx][buyornot][k]=max(sell,notsell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int k=2;
        int n=prices.size();
    vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return memo(0,1,k,prices,dp);
    }
};

/* Tabulation Code :
   int maxProfit(vector<int>& prices) {
        int k=2;
        int n=prices.size();
vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
       // base cases 
        for(int inx=0;inx<n;inx++){
            for(int b=0;b<=1;b++) 
                dp[inx][b][0]=0;
        }
        for(int b=0;b<=1;b++){
            for(int t=0;t<=k;t++){
                dp[n][b][t]=0;
            }
        }
        for(int inx=n-1;inx>=0;inx--){
            for(int b=0;b<=1;b++){
                for(int t=1;t<=k;t++){ // t=0 is assigned already
                    if(b==1){ // can buy 
                       int buy=0-prices[inx]+dp[inx+1][0][t];
                       int notbuy=dp[inx+1][1][t];
                       dp[inx][b][t]=max(buy,notbuy);
                    }
                    else{ // can sell
                       int sell=prices[inx]+dp[inx+1][1][t-1];
                       int notsell=dp[inx+1][0][t];
                       dp[inx][b][t]=max(sell,notsell);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
*/

/* Space Optimization
       int maxProfit(vector<int>& prices) {
        int k=2;
        int n=prices.size();
        vector<vector<int>>inxplusone(2,vector<int>(3,0));
        vector<vector<int>>currinx(2,vector<int>(3,0));
        for(int inx=n-1;inx>=0;inx--){
            for(int b=0;b<=1;b++){
                for(int t=1;t<=k;t++){ // t=0 is assigned already
                    if(b==1){ // can buy 
                       int buy=0-prices[inx]+inxplusone[0][t];
                       int notbuy=inxplusone[1][t];
                       currinx[b][t]=max(buy,notbuy);
                    }
                    else{ // can sell
                       int sell=prices[inx]+inxplusone[1][t-1];
                       int notsell=inxplusone[0][t];
                       currinx[b][t]=max(sell,notsell);
                    }
                }
            }
            inxplusone=currinx;
        }
        return inxplusone[1][k];
    }
*/