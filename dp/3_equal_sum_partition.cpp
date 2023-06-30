//Recursive

class Solution {
public:
    int dp[201][10001];
    bool canPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int sum=0;
        for(auto ele : nums) sum += ele;
        if(sum&1) return false;
        return can(nums, sum/2, nums.size());
    }

    bool can(vector<int> &nums, int sum, int n){
        if(sum == 0) return true;
        if(n<=0) return false;

        if(dp[n][sum] != -1) return dp[n][sum];

        if(nums[n-1] <= sum) return dp[n][sum] = can(nums, sum-nums[n-1], n-1) or can(nums, sum, n-1);
        return dp[n][sum] = can(nums, sum, n-1);
    }
};

//TOP DOWN

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n=nums.size();
        for(auto ele : nums) sum+=ele;
        if(sum&1) return false;
        sum/=2;
        int dp[n+1][sum+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j] = false;
                if(j==0) dp[i][j] = true;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1] <= j) dp[i][j] = dp[i-1][j-nums[i-1]] or dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][sum];

    }
};