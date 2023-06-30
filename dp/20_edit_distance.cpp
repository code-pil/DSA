class Solution {
  public:
    vector<vector<int>> dp;
    int editDistance(string s, string t) {
        // Code here
        int n=s.length(), m=t.length();
        dp = vector<vector<int>> (n+1, vector<int> (m+1, -1));
        return solve(s, t, n, m);
    }
    
    int solve(string s, string t, int n, int m){
        if(n==0 or m==0) return max(n, m);
        
        if(dp[n][m] != -1) return dp[n][m];
        
        if(s[n-1] ==  t[m-1]) return dp[n][m] = solve(s, t, n-1, m-1);
        else{
            return dp[n][m] = 1+min(solve(s, t, n, m-1), min(solve(s, t, n-1, m), solve(s, t, n-1, m-1)));
        }
    }
};