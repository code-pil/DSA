class Solution{
	public:
	vector<vector<int>> dp;
	int MinCoin(vector<int>nums, int amt)
	{
	    // Code here
	    int n=nums.size();
	    dp = vector<vector<int>> (n+1, vector<int> (amt+1, -1));
	    int coins = mincoins(nums, n-1, amt);
	    return coins>=1e9?-1:coins;
	}
	
	int mincoins(vector<int> &nums, int n, int amt){
	    

		//you can write your own base case

	    // if(amt==0) return 0;
	    // if(n<0) return 1e9;

	    //another base case
	    if(n==0){
	        if(amt%nums[0]) return 1e9;
	        return amt/nums[0];
	    }
	    
	    if(dp[n][amt] != -1) return dp[n][amt];
	    
	    int notake = mincoins(nums, n-1, amt);
	    
	    int take = INT_MAX;
	    
	    if(nums[n] <= amt) take = 1+mincoins(nums, n, amt-nums[n]);
	    
	    return dp[n][amt] = min(take, notake);
	}
	
};


//top down
class Solution{
	public:
	int MinCoin(vector<int>nums, int amt)
	{
	    // Code here
	    int n=nums.size();
	    vector<vector<int>> dp(n+1, vector<int> (amt + 1));
	    for(int i=0;i<=n;i++){
	        for(int j=0;j<=amt;j++){
	            if(j==0) dp[i][j] = 0;
	            if(i==0) dp[i][j] = 1e9;
	        }
	    }
	    
	    for(int i=0;i<=amt;i++){
	        if(i%nums[0] == 0) dp[1][i] = i/nums[0];
	        else dp[1][i] = 1e9;
	    }
	    
	    for(int i=2;i<=n;i++){
	        for(int j=1;j<=amt;j++){
	            int take = 1e9;
	            if(nums[i-1] <= j) take = 1+dp[i][j-nums[i-1]];
	            int notake = dp[i-1][j];
	            dp[i][j] = min(take, notake);
	        }
	    }
	    
	    return dp[n][amt]>=1e9?-1:dp[n][amt];
	}
};

// space optimization

class Solution{
	public:
	int MinCoin(vector<int>nums, int amt)
	{
	    // Code here
	    int n=nums.size();
	    vector<int> dp(amt+1, 1e9);
	    
	    dp[0]=0;
	    for(int i=1;i<=amt;i++){
	        if(i%nums[0] == 0) dp[i] = i/nums[0];
	    }
	    
	    
	    for(int i=1;i<n;i++){
	        for(int j=1;j<=amt;j++){
	            int take = 1e9;
	            if(nums[i] <= j) take = 1+dp[j-nums[i]];
	            int notake = dp[j];
	            dp[j] = min(take, notake);
	        }
	    }
	    
	    return dp[amt]>=1e9?-1:dp[amt];
	}
};