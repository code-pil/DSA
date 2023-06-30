class Solution{
    public:
    
    int longestCommonSubstr(string S1, string S2, int n, int m)
    {
        int dp[n+1][m+1];
        
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0) dp[i][j] = 0;
                else if(S1[i-1] == S2[j-1]) dp[i][j] = 1+dp[i-1][j-1], ans = max(ans, dp[i][j]);
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
};


//space optimization


class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        vector<int> prev(m+1, 0), cur(m+1, 0);
        
        int ans=0;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0) cur[j] = 0;
                else if(S1[i-1] == S2[j-1]) cur[j] = 1+prev[j-1], ans = max(ans, cur[j]);
                else cur[j] = 0;
            }
            prev = cur;
        }
        return ans;
    }
};
