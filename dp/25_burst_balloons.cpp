class Solution {
public:

    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        dp = vector<vector<int>> (n+1, vector<int> (n+1, -1));
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        return solve(nums, 1, n);
    }

    int solve(vector<int> &v, int i, int j){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int coins = 0;
        for(int k=i;k<=j;k++){
            int lCoins = solve(v, i, k-1);
            int rCoins = solve(v, k+1, j);

            coins = max(coins, lCoins+rCoins+v[i-1]*v[k]*v[j+1]);
        }
        return dp[i][j] = coins;
    }
};

// top down

class Solution {
public:
    int maxCoins(vector<int>& v) {
        int n = v.size();
        v.push_back(1);
        v.insert(v.begin(), 1);
        vector<vector<int>> dp(n+2, vector<int> (n+2, 0));

        for(int i=n;i>=1;i--){
            for(int j=1;j<=n;j++){
                if(i<=j){
                    int coins = 0;
                    for(int k=i;k<=j;k++){
                        coins = max(coins, v[i-1]*v[k]*v[j+1]+dp[i][k-1]+dp[k+1][j]);
                    }
                    dp[i][j] = coins;
                }
            }
        }
        return dp[1][n];
    }
};