
// gfg : https://practice.geeksforgeeks.org/problems/longest-repeating-subsequence2004/1
			
		 // 01234567
//      s = aabebcdd
// s1 = s = aabebcdd
		 // 01234567
// so just find LCS where i!=j means in s position of a is 0 is matched with s2's a at position 1

class Solution {
	public:
		int LongestRepeatingSubsequence(string str){
		    int n=str.length();
		    int dp[n+1][n+1];
		    for(int i=0;i<=n;i++){
		        for(int j=0;j<=n;j++){
		            if(i==0 or j==0) dp[i][j]=0;
		            else if(i!=j and str[i-1] == str[j-1]) dp[i][j] = 1+dp[i-1][j-1];
		            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		        }
		    }
		    
		    return dp[n][n];
		}

};