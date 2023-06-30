//Leetcode : https://leetcode.com/problems/shortest-bridge/description/ 

//BFS+DFS


class Solution {
public: 
    vector<int> di = {-1, 0, 0, +1};
    vector<int> dj = {0, -1, +1, 0};

    bool validate(int x, int y, int n){
        return x>=0 and x<n and y>=0 and y<n;
    }

    void dfs(vector<vector<int>> &grid, vector<vector<int>> &vis, int x, int y){
        vis[x][y] = 1;
        int n = grid.size();
        for(int k=0;k<4;k++){
            int newx = x+di[k];
            int newy = y+dj[k];
            if(validate(newx, newy, n) and grid[newx][newy] and !vis[newx][newy]){
                dfs(grid, vis, newx, newy);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> vis(n, vector<int> (n, 0));
        int firstX, firstY;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]){
                    firstX = i;
                    firstY = j;
                    break;
                }
            }
        }        
        dfs(grid, vis, firstX, firstY);

        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]){
                    q.push({i, j});
                }
            }
        }

        int res = 0;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto [x, y] = q.front();
                q.pop();
                for(int k=0;k<4;k++){
                    int newx = x+di[k];
                    int newy = y+dj[k];
                    if(validate(newx, newy, n) 
                        and grid[newx][newy] 
                        and !vis[newx][newy])
                    {
                        return res;
                    }
                    else if(validate(newx, newy, n) and !vis[newx][newy]){
                        vis[newx][newy] = 1;
                        q.push({newx, newy});
                    }
                }
            }
            res++;
        }

        return -1;

        
    }
};