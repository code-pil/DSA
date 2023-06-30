//BOTTOM UP

class Solution{
public:
    vector<vector<int>> dp;
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        dp = vector<vector<int>> (N+1, vector<int> (W+1, -1));
        
        return knap(N, W, val, wt);
    }
    
    int knap(int n, int W, int val[], int wt[]){
        if(n<=0 or W<=0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n-1] <= W) return dp[n][W] = max(val[n-1] + knap(n, W-wt[n-1], val, wt), knap(n-1, W, val, wt));
        
        return dp[n][W] = knap(n-1, W, val, wt);
    }
};


//TOP DOWN
class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int> (W+1));
        
        for(int i=0;i<=N;i++){
            for(int j=0;j<=W;j++){
                if(i==0 or j==0) dp[i][j]=0;
                
            }
        }
        
        for(int i=1;i<=N;i++){
            for(int j=1;j<=W;j++){

                // slight change in condition from 01 knapsack

                //                                            |  here i in place of i-1
                //                                            x  
                if(wt[i-1] <= j) dp[i][j] = max(val[i-1] + dp[i][j-wt[i-1]], dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[N][W];
    }
};

