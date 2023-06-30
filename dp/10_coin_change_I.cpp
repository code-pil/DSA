class Solution {
  public:
    long long int count(int coins[], int n, int sum) {

        // code here.
        vector<vector<long long int>> dp(n+1, vector<long long int> (sum+1));
        for(int i=0;i<=n;i++) dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i-1] <= j) dp[i][j] = dp[i][j-coins[i-1]]*1LL + dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};

//Space optimization

class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        vector<long long> dp(sum+1, 0);
        dp[0]=1;
        for(int i=0;i<N;i++){
            for(int j=1;j<=sum;j++){
                if(coins[i] <= j) dp[j] += dp[j-coins[i]];
            }
        }
        return dp[sum];
    }
};