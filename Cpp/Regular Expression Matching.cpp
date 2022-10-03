class Solution {
public:
    int dp[100][100];
    bool helper(string s, string p, int i, int j) {
        if (j == p.length()) return i == s.length();
        if (dp[i][j] >= 0) return dp[i][j];
        bool isFirstMatch = (i < s.length()) && ((s[i] == p[j]) || (p[j] == '.'));
        bool ans;
        if ((j + 1) < p.length() && p[j + 1] == '*') {
            return ans = (helper(s, p, i, j + 2)) || (isFirstMatch && helper(s, p, i + 1, j));
        }
        else {
            return ans = (isFirstMatch && helper(s, p, i + 1, j + 1));
        }
        return dp[i][j] = ans;
    }

    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        bool ans = helper(s, p, 0, 0);
        return ans;
    }
};
//Question is from leetcode
//https://leetcode.com/problems/regular-expression-matching/