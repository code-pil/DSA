
//Bottom Up Recursive

class Solution
{
    public:
    int dp[1001][1001];
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code her3
       memset(dp, -1, sizeof(dp));
       return knap(wt, val, 0, W, n);
    }
    
    int knap(int wt[], int val[], int i, int W, int n){
        if(i==n or W<=0) return 0;
        
        if(dp[i][W] != -1) return dp[i][W];
        
        if(wt[i]<=W) return dp[i][W] = max(val[i]+knap(wt, val, i+1, W-wt[i], n), knap(wt, val, i+1, W, n));
        
        return dp[i][W] = knap(wt, val, i+1, W, n);
    }
};

//Bottom Up Recursive
class Solution
{
    public:
    int dp[1001][1001];
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       memset(dp, -1, sizeof(dp));
       return knap(wt, val, W, n);
    }
    
    int knap(int wt[], int val[], int W, int n){
        if(n<=0 or W<=0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n-1]<=W) return dp[n][W] = max(val[n-1]+knap(wt, val, W-wt[n-1], n-1), knap(wt, val, W, n-1));
        
        return dp[n][W] = knap(wt, val, W, n-1);
    }
};

//Top Down
class Solution
{
    public:  
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       int dp[n+1][W+1];
       for(int i=0;i<=n;i++){
           for(int j=0;j<=W;j++){
               if(i==0 or j==0) dp[i][j]=0;
           }
       }
       
       for(int i=1;i<=n;i++){
           for(int j=1;j<=W;j++){
               if(wt[i-1] <= j) dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]], dp[i-1][j]);
               else dp[i][j] = dp[i-1][j];
           }
       }
       
       return dp[n][W];
    }
};
