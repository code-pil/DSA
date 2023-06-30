// GFG: https://practice.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-a-binary-maze

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source, pair<int, int> dest) {
        // code here
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        vector<int> di = {-1, 0, 0, +1};
        vector<int> dj = {0, -1, +1, 0};
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> vis(n, vector<int> (m,0));
        
        pq.push({0 ,source.first, source.second});
        vis[source.first][source.second]=1;
        
        while(!pq.empty()){
            
            int dis = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            
            vis[x][y]=1;
            if(x == dest.first and y == dest.second) return dis;
            
            for(int i=0;i<4;i++){
                int newx = x+di[i];
                int newy = y+dj[i];
                if(newx>=0 and newy>=0 and newx<n and newy<m and !vis[newx][newy] and grid[newx][newy]){
                    vis[newx][newy]=1;
                    pq.push({dis+1, newx, newy});
                }
            }
            
        }
        
        return -1;
        
        
    }
};