/*

Simple BFS Solution.

You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Leetcode: https://leetcode.com/problems/rotting-oranges/description/

TC : O(N*M)
SC : O(N*M)

*/

/*------------------------------------------------------
you can also use visited grid if not want to alter original data
-----------------------------------------------*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        //{{row, col}, time}
        queue<pair<pair<int,int>,int>> q;
        int cntFresh=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2) q.push({{i,j},0});
                else if(grid[i][j]==1) cntFresh++;
            }
        }

        int time=0;
        vector<int> di = {-1, 0, 0, +1};
        vector<int> dj = {0, -1, +1, 0};
        int ct=0;
        while(!q.empty()){
            int r=q.front().first.first;
            int c=q.front().first.second;
            int t=q.front().second;
            time = max(t, time);
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=r+di[i];
                int ncol=c+dj[i];

                if(nrow>=0 and ncol>=0 and nrow<n and ncol<m and grid[nrow][ncol]==1){
                    grid[nrow][ncol]=2;
                    q.push({{nrow,ncol},t+1});
                    ct++;
                }

            }

        }
        if(ct != cntFresh) return -1;
        return time;

    }
};