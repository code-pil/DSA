// recursive
class Solution
{
    int dp[1001][1001];
    
    public:
    int lcs(int x, int y, string s1, string s2)
    {
        memset(dp, -1, sizeof(dp));
        return LCS(x, y, s1, s2);
        
    }
    
    int LCS(int x, int y, string s1, string s2){
        
        if(x==0 or y==0) return dp[x][y] = 0;
        
        if(dp[x][y] != -1) return dp[x][y];
            
        if(s1[x-1]==s2[y-1]) return dp[x][y] = 1+LCS(x-1,y-1,s1,s2);
        
        return dp[x][y] = max(LCS(x-1,y,s1,s2), LCS(x,y-1,s1,s2));
    }
};


// top down

class Solution
{
    public:
    int lcs(int x, int y, string s1, string s2)
    {
        int dp[x+1][y+1];
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 or j==0) dp[i][j]=0;
                else if(s1[i-1]==s2[j-1]) dp[i][j] = 1+dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[x][y];
    }
};

//space optimization

// function to find longest common subsequence

class Solution
{
    public:
    int lcs(int x, int y, string s1, string s2)
    {
        vector<int> prev(y+1, 0), cur(y+1, 0);
        for(int i=0;i<=x;i++){
            for(int j=0;j<=y;j++){
                if(i==0 or j==0) cur[j] = 0;
                else if(s1[i-1]==s2[j-1]) cur[j] = 1+prev[j-1];
                else cur[j] = max(prev[j], cur[j-1]);
            }
            prev = cur;
        }
        return cur[y];
    }
};
