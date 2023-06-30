//Leetcode: https://leetcode.com/problems/01-matrix/description/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        vector<vector<int>> ans(n, vector<int> (m));
        vector<vector<int>> vis(n, vector<int> (m));
        vector<int> di = {-1, 0, 0, +1};
        vector<int> dj = {0, -1, +1, 0};

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        } 
        int ct=1;
        while(!q.empty()){
            int size = q.size();
            cout << size << endl;
            for(int i=0;i<size;i++){
                auto [x,y] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int newi = x+di[k];
                    int newj = y+dj[k];
                    if(newi>=0 and newj>=0 and newi<n and newj<m and mat[newi][newj] and !vis[newi][newj]){
                        ans[newi][newj]=ct;
                        q.push({newi, newj});
                        vis[newi][newj]=1;
                    }
                }
            }
            ct++;
        }
        return ans;
    }
};