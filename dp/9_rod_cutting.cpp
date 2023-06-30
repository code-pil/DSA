//TOP DOWN
class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i <= j) dp[i][j] = max(price[i-1]+dp[i][j-i], dp[i-1][j]);
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][n];
    }
};


//Recursive
class Solution{
  public:
    vector<vector<int>> dp;
    int cutRod(int price[], int n) {
        //code here
        dp = vector<vector<int>> (n+1, vector<int> (n+1, -1));
        return find(price, n, n);
    }
    
    int find(int price[], int n, int length){
        if(length==0 or n==0) return 0;
        
        if(dp[n][length] != -1) return dp[n][length];
        
        if(n <= length) return dp[n][length] = max(price[n-1]+find(price, n, length-n), find(price, n-1, length));
        
        return dp[n][length] = find(price, n-1, length);
    }
    
    
};