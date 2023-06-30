//gfg : https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1

class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int n, int m)
    {
        //code here
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 or j==0) dp[i][j] = 0;
                else if(X[i-1]==Y[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return n+m-dp[n][m];
        
    }
};


// print scs

//leetcode : https://leetcode.com/problems/shortest-common-supersequence/description/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n=str1.length(),m=str2.length();
        int dp[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0||j==0) dp[i][j]=0;
                else if(str1[i-1]==str2[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        int p = n, q = m;
        string ans;
        while(p>0 and q>0){
            if(str1[p-1] == str2[q-1]) ans+= str1[p-1], p--, q--;
            else if(dp[p][q-1] < dp[p-1][q]) ans += str1[p-1], p--;
            else ans += str2[q-1], q--;
        }
        while(p>0) ans += str1[p-1], p--;
        while(q>0) ans += str2[q-1], q--;
        reverse(ans.begin(), ans.end());
        return ans;
        
    }
};