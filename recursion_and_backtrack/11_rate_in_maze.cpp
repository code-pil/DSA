class Solution{
    public:
    
    void path(vector<vector<int>> m, int n, int i, int j, vector<string> &ans, string ds, vector<vector<int>> &vis){
        if(i == n-1 && j == n-1){
             ans.push_back(ds);
             return;
        }
        
        if(i<n-1 && !vis[i+1][j] && m[i+1][j] == 1){
            vis[i][j]=1;
            path(m, n, i+1, j, ans, ds+'D', vis);
            vis[i][j]=0;
        }
        
        if(j<n-1 && !vis[i][j+1] && m[i][j+1] == 1){
            vis[i][j]=1;
            path(m, n, i, j+1, ans, ds+'R', vis);
            vis[i][j]=0;
        }
        
        if(j>0 && !vis[i][j-1] && m[i][j-1] == 1){
            vis[i][j]=1;
            path(m, n, i, j-1, ans, ds+'L', vis);
            vis[i][j]=0;
        }
        
        if(i>0 && !vis[i-1][j] && m[i-1][j] == 1){
            vis[i][j]=1;
            path(m, n, i-1, j, ans, ds+'U', vis);
            vis[i][j]=0;
        }
        
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        string ds;
        if(m[0][0]) path(m, n, 0, 0, ans, ds, vis);
        return ans;
    }
};


// di={1 0 0 -1} dj={0 1 -1 0} method

class Solution{
    public:
    
    void path(vector<vector<int>> m, vector<string> &ans, int i, int j, int n, vector<int> di, vector<int> dj, string move, vector<vector<int>> &vis){
        if(i == n-1 && j == n-1){
            ans.push_back(move);
            return;
        }
        
        string dir = "DLRU";
        
        for(int idx = 0; idx < 4; idx+=1){
            int nexti = i + di[idx];
            int nextj = j + dj[idx];
            if(nexti >=0 && nextj >=0 && nexti<n && nextj<n && !vis[nexti][nextj] && m[nexti][nextj] == 1){
                vis[i][j]=1;
                path(m, ans, nexti, nextj, n, di, dj, move+dir[idx], vis);
                vis[i][j]=0;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<int>> vis(n, vector<int> (n,0));
        vector<int> di = {+1, 0, 0, -1};
        vector<int> dj = {0, -1, +1, 0};
        
        if(m[0][0]) path(m, ans, 0, 0, n, di, dj, "", vis);
        return ans;
    }
};
