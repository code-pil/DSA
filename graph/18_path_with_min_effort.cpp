//GFG: https://practice.geeksforgeeks.org/problems/path-with-minimum-effort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=path-with-minimum-effort

class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        int n = heights.size(), m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, INT_MAX));
        
        vector<int> di = {-1,0,0,+1};
        vector<int> dj = {0,+1,-1,0};
        
        pq.push({0, 0, 0});
        dist[0][0] = 0;
        
        while(!pq.empty()){
            int diff = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            
            if(x == n-1 and y == m-1){
                return diff;
            }
            
            for(int i=0;i<4;i++){
                int newx = x+di[i];
                int newy = y+dj[i];
                
                if(newx>=0 and newy>=0 and newx<n and newy<m){
                    int newdiff = max(diff, abs(heights[x][y] - heights[newx][newy]));
                    
                    if(newdiff < dist[newx][newy]){
                        dist[newx][newy] = newdiff;
                        pq.push({newdiff, newx, newy});
                    }
                    
                }
            }
        }
        return -1;
    }
};