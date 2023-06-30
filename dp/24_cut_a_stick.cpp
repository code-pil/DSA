class Solution {
public:
    vector<vector<int>> dp;
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        dp = vector<vector<int>> (c+1, vector<int> (c+1, -1));
        return solve(cuts, 1, cuts.size()-2);
    }
    int solve(vector<int> &cuts, int i, int j){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int minCost = INT_MAX;
        for(int k=i;k<=j;k++){
            int leftCost = solve(cuts, i, k-1);
            int rightCost = solve(cuts, k+1, j);

            minCost = min(minCost, leftCost+rightCost);
        }
        minCost += cuts[j+1]-cuts[i-1];
        return dp[i][j] = minCost;
    }
};


// top down

class Solution {
public:
    vector<vector<int>> dp;
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(c+2, vector<int> (c+2, 0));

        for(int i=c;i>=1;i--){
            for(int j=1;j<=c;j++){
                if(i<=j){
                    int minCost = INT_MAX;
                    for(int k=i;k<=j;k++){      
                        minCost = min(minCost, cuts[j+1]-cuts[i-1]+dp[i][k-1]+dp[k+1][j]);
                    } 
                    dp[i][j] = minCost;
                }
            }
        }


        return dp[1][c];
    }
};