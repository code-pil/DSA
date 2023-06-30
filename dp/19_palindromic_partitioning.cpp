// My version
class Solution{
public:

    vector<int> dp;
    int palindromicPartition(string &s) {
        dp = vector<int> (s.length()+1, -1);
        return solve(s, 0);
    }

    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    int solve(string s, int i){
        if(i==s.length()) return -1;
        
        if(dp[i] != -1) return dp[i];

        int minPartitions = 1e9;
        for(int idx=i;idx<s.length();idx++){
            if(isPalindrome(s, i, idx)){
                minPartitions = min(minPartitions, 1+solve(s, idx+1)); 
            }
        }

        return dp[i] = minPartitions>=1e9?0:minPartitions;
    }
};

// MCM version

class Solution {
public:
    vector<vector<int>> dp;
    int minCut(string s) {
        int n = s.length();
        dp = vector<vector<int>> (n, vector<int> (n, -1));
        return solve(s, 0, n-1);
    }

    bool isPalindrome(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        return true;
    }

    int solve(string &s, int i, int j){
        if(i>=j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        if(isPalindrome(s, i, j)) return 0;


        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            int temp = 1 + solve(s, i, k) + solve(s, k+1, j);

            if(temp < ans) ans = temp;
        }

        return dp[i][j] = ans;
    }
};

//Optimized version

