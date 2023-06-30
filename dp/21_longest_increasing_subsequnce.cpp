class Solution {
public:

    vector<vector<int>> dp;
    int lengthOfLIS(vector<int>& nums) {
        dp = vector<vector<int>> (nums.size()+1, vector<int> (nums.size()+1, -1));
        return func(nums, 0, -1);
    }
    int func(vector<int> &v, int i, int last){
        if(i==v.size()) return 0;
        if(dp[i][last+1] != -1) return dp[i][last+1];
        if(last == -1 or v[i] > v[last]){
            return dp[i][last+1] = max(1+func(v, i+1,i), func(v, i+1, last));
        }

        return dp[i][last+1] = func(v, i+1, last);
    }
};

// another approach for this using 1d dp

class Solution {
public:

    int lengthOfLIS(vector<int>& v) {
        int n = v.size();
        vector<int> dp(n, 1);
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(v[i]>v[j]){
                    dp[i] = max(dp[i], 1+dp[j]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
    
};

// for printing LIS maintain hash of prev for each element
// update when value changes to max of 1+prevdp 