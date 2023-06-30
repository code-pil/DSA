// GFG :https://practice.geeksforgeeks.org/problems/target-sum-1626326450/1

class Solution {
  public:
    int findTargetSumWays(vector<int> &arr, int d) {
        // Code here
        int n=arr.size();
        int mod = 1e9+7;
        int sum=0;
        for(auto ele : arr) sum+=ele;
        
        if(sum<d or (sum+d)&1) return 0;

        // s1-s2 = d
        // s1+s2 = sum
        // 2*s1 = d+sum
        
        
        sum = (d+sum)/2;
        
        vector<vector<int>> dp(n+1, vector<int> (sum+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1] <= j) dp[i][j] = (dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod)%mod;
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        
        return dp[n][sum]%mod;
        
    }
};