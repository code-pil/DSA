class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<int> inPath(n, false);
        vector<int> vis(n, false);

        vector<int> adj[n];
        for(auto it : prerequisites){
            adj[it[1]].push_back(it[0]);
        }

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i, vis, inPath, adj)) return false;
            }
        }
        return true;
    }

    bool dfs(int node, vector<int> &vis, vector<int> &inPath, vector<int> adj[]){
        inPath[node]=1;
        vis[node]=1;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                if(dfs(adjnode, vis, inPath, adj)) return true;
            }
            else if(inPath[adjnode]) return true;
        }
        inPath[node]=false;
        return false;
    }
};