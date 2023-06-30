// Bottom up
class Solution{

	public:
	int mod = 1e9+7;
    vector<vector<int>> dp;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes her
        dp = vector<vector<int>> (n+1, vector<int> (sum+1, -1));
        return (find(arr, n, sum))%mod;
	}
	
	int find(int arr[], int n, int sum){


		//Here we have to write n==0 and sum==0 to handle zeros in arr other wise it will
		//give wrong ans
	    if(n==0 and sum==0) return 1;
	    if(n==0) return 0;
	    
	    if(dp[n][sum] != -1) return dp[n][sum];
	    
	    if(arr[n-1] <= sum) return dp[n][sum] = (find(arr, n-1, sum-arr[n-1])%mod+find(arr, n-1, sum)%mod)%mod;
	    
	    return dp[n][sum] = find(arr, n-1, sum)%mod;
	}
	  
};

//Top Down
class Solution{

	public:
	int mod=1e9+7;
	
	//other method to handle zeros 
	int handle_zero(int arr[], int k){
	    int zeros=0;
	    for(int i=0;i<=k;i++){
	        zeros+=arr[i]==0;
	    }
        return 1<<zeros;
	}
	
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        
        int dp[n+1][sum+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i==0) dp[i][j]=0;
                // if(j==0) dp[i][j]=1; // for j=0
                if(j==0) dp[i][j]=handle_zero(arr, i);
            }
        }
        
        for(int i=1;i<=n;i++){
            //Here we can start with j=0 cause there is possiblity that sum=0 and 
            //in remaining elements zeros are possible so
            for(int j=1;j<=sum;j++){
                if(arr[i-1] <= j) dp[i][j] = (dp[i-1][j-arr[i-1]]%mod + dp[i-1][j]%mod) %mod;
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
	}
	  
};