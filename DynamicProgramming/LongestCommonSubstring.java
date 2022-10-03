/*
Given two strings ‘X’ and ‘Y’, find the length of the longest common substring. 

Input : X = “abcdxyz”, y = “xyzabcd” 
Output : 4 
Explanation:
The longest common substring is “abcd” and is of length 4.
*/

/*
Let m and n be the lengths of the first and second strings respectively.

A simple solution is to one by one consider all substrings of the first string and for every substring check if it is a substring in the second string. Keep track of the maximum length substring. There will be O(m^2) substrings and we can find whether a string is substring on another string in O(n) time (See this). So overall time complexity of this method would be O(n * m2)

Dynamic Programming can be used to find the longest common substring in O(m*n) time. The idea is to find the length of the longest common suffix for all substrings of both strings and store these lengths in a table. 
*/

class LongestCommonSubstring {
	static int lcs(char s1[], char s2[], int m, int n){
		int LCStuff[][] = new int[m + 1][n + 1];
	
		// To store length of the longest
		// common substring
		int result = 0;

		// Following steps build
		// LCSuff[m+1][n+1] in bottom up fashion
		for (int i = 0; i <= m; i++){
			for (int j = 0; j <= n; j++){
				if (i == 0 || j == 0){
					LCStuff[i][j] = 0;
                }
				else if (s1[i - 1] == s2[j - 1]){
					LCStuff[i][j] = LCStuff[i - 1][j - 1] + 1;
					result = Integer.max(result, LCStuff[i][j]);
				}
				else{
					LCStuff[i][j] = 0;
                }
			}
		}
		return result;
	}

	// Driver Code
	public static void main(String[] args){
		String s1 = "zxabcdezy";
		String s2 = "yzabcdezx";

		int m = s1.length();
		int n = s2.length();

		System.out.println(lcs(s1.toCharArray(), s2.toCharArray(), m, n));
	}
}
