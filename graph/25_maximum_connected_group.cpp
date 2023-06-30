
//GFG: https://practice.geeksforgeeks.org/problems/maximum-connected-group/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=maximum-connected-group

class DisjointSet{
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(rank[pu] > rank[pv]) parent[pv] = pu;
        else if(rank[pu] < rank[pv]) parent[pu] = pv;
        else parent[pu] = pv, rank[pv]++;
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] > size[pv]) parent[pv] = pu, size[pu] += size[pv];
        else parent[pu] = pv, size[pv] += size[pu];
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int n=grid.size(), m=grid[0].size();
        DisjointSet ds(n*m);
        vector<int> di = {-1,0,0,+1};
        vector<int> dj = {0,+1,-1,0};
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int x = i;
                    int y = j;
                    int v = m*x+y;
                    for(int k=0;k<4;k++){
                        int newx = x+di[k];
                        int newy = y+dj[k];
                        int u = m*newx+newy;
                        if(newx>=0 and newy>=0 and newx<n and newy<m and grid[newx][newy]){
                            if(ds.findParent(u) != ds.findParent(v)){
                                ds.unionBySize(u, v);
                            }
                        }
                    }
                }
                
            }
        }
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0){
                    int x = i;
                    int y = j;
                    int size=1;
                    set<int> components;
                    for(int k=0;k<4;k++){
                        int newx = x+di[k];
                        int newy = y+dj[k];
                        int u = m*newx+newy;
                        if(newx>=0 and newy>=0 and newx<n and newy<m and grid[newx][newy]){
                            int parent = ds.findParent(u);
                            components.insert(parent);
                        }
                    }
                    for(auto it : components){
                        size += ds.size[it];
                    }
                    ans = max(ans, size);
                }
            }
        }
        
        
        
        return ans==0?n*m:ans;
    }
};
