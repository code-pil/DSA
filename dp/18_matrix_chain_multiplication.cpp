// User function Template for C++

class Solution{
public:
    vector<vector<int>> dp;
    int matrixMultiplication(int N, int arr[])
    {
        // code here
        dp = vector<vector<int>> (N+1, vector<int> (N+1, -1));
        return solve(arr, 1, N-1);
    }
    
    int solve(int arr[], int i, int j){
        if(i>=j) return 0;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            ans = min(ans, arr[i-1]*arr[k]*arr[j] + solve(arr, i, k) + solve(arr, k+1, j));
        }
        return dp[i][j]=ans;
    }
};