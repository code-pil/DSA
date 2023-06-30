
class Solution{
public:

    vector<vector<vector<int>>> dp;
    int countWays(int N, string s){
        int n = s.length();
        dp = vector<vector<vector<int>>> (n+1, vector<vector<int>> (n+1, vector<int> (2, -1)));
        return solve(s, 0, n-1, 1);
    }
    
    int solve(string &s, int i, int j, int which){
        if(i>j) return 0;
        
        if(dp[i][j][which] != -1) return dp[i][j][which];
        
        if(i==j){
            if(which) return s[i] == 'T';
            if(!which) return s[i] == 'F';
        }
        
        int ct=0;
        for(int k=i+1;k<=j-1;k+=2){
            int leftT = solve(s, i, k-1, 1);
            int rightT = solve(s, k+1, j, 1);
            int leftF = solve(s, i, k-1, 0);
            int rightF = solve(s, k+1, j, 0);
            
            if(s[k] == '|') {
                if(which) ct += (leftT*rightT) + (leftT*rightF) + (leftF*rightT);
                else ct += (leftF*rightF);
            }
            else if(s[k] == '&'){
                if(which) ct += (leftT*rightT);
                else ct += (leftT*rightF) + (leftF*rightT) + (leftF*rightF);
            }
            else{
                if(which) ct+= (leftT*rightF) + (leftF*rightT);
                else ct += (leftT*rightT) + (leftF*rightF);
            };
            
        }
        
        return dp[i][j][which] = ct%1003;
        
    }
};