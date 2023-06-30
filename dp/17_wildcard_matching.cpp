class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size(), m=p.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1));
        dp[0][0] = true;
        for(int i=1;i<=n;i++) dp[i][0] = false;
        for(int i=1;i<=m;i++){
            bool flag = true;
            for(int j=1;j<=i;j++){
                if(p[j-1]!='*'){
                    flag = false;
                    break;
                }
            }
            dp[0][i] = flag;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(p[j-1] == '?' or s[i-1] == p[j-1]) dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] == '*') dp[i][j] = dp[i-1][j] or dp[i][j-1];
                else dp[i][j] = false;
            }
        }

        return dp[n][m];
    }
    // bool possible(string s, string p, int n, int m){
    //     if(n==0 and m==0) return true;
    //     if(n>0 and m==0) return false;
    //     if((n==0 and m>0)){
    //         for(int i=m-1;i>=0;i--){
    //             if(p[i] != '*') return false;
    //         }
    //         return true;
    //     }

    //     if(dp[n][m] != -1) return dp[n][m];
        
    //     if(p[m-1] == '?' or s[n-1] == p[m-1]){
    //         return dp[n][m] = possible(s, p, n-1, m-1);
    //     }
    //     else if(p[m-1] == '*') return dp[n][m] = possible(s, p, n-1, m) or possible(s, p, n, m-1);
        
    //     return dp[n][m] = false;
    // }
};