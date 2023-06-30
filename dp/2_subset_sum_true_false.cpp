//Bottom Up

class Solution{   
public:
    int dp[101][10001];
    bool isSubsetSum(vector<int>arr, int sum){
        memset(dp, -1, sizeof(dp));
        return isPresent(arr, sum, arr.size());
    }
    
    bool isPresent(vector<int> &v, int sum, int n){
        if(sum == 0) return true;
        if(n<=0) return false;
        
        if(dp[n-1][sum] != -1) return dp[n-1][sum];
        
        if(v[n-1]<=sum) return dp[n-1][sum] = isPresent(v, sum-v[n-1], n-1) or isPresent(v, sum, n-1);
        
        return dp[n-1][sum] = isPresent(v, sum, n-1);
    }
    
};

//Top Down

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        int dp[n+1][sum+1];
        
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
            }
        }
        
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i-1] <= j) dp[i][j] = dp[i-1][j-arr[i-1]] or dp[i-1][j];
                else dp[i][j] = dp[i-1][j];
            }
        }
        
        return dp[n][sum];
    }
};

//TOP DOWN SPACE OPTIMIZATION
// two 1d array;

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<int> prev(sum+1, 0), cur(sum+1, 0);
        prev[0]=1;
        cur[0]=1;
        
        for(int i=0;i<n;i++){
            for(int j=1;j<sum+1;j++){
                if(arr[i] <= j) cur[j] = prev[j-arr[i]] or prev[j];
                else cur[j] = prev[j];
            }
            prev = cur;
        }
        
        return cur[sum];
    }
};

//Further space optimization
// one 1d array

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        int n=arr.size();
        vector<int> dp(sum+1, 0);
        dp[0]=1;
        
        for(int i=0;i<n;i++){
            for(int j=sum;j>=arr[i];j--){
                dp[j] |= dp[j-arr[i]];
            }
        }
        
        return dp[sum];
    }
};