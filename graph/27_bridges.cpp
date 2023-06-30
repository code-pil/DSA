//https://leetcode.com/problems/critical-connections-in-a-network/description/

class Solution {
public:
    int timer=1;
    void dfs(int node, vector<int> &vis, int parent, vector<int> adj[], vector<int> &tin,
    vector<int> &low, vector<vector<int>> &bridges){
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        for(auto adjnode : adj[node]){
            if(adjnode == parent) continue;
            if(!vis[adjnode]){
                dfs(adjnode, vis, node, adj, tin, low, bridges);
                low[node] = min(low[node], low[adjnode]);

                if(low[adjnode] > tin[node]){
                    bridges.push_back({adjnode, node});
                }
            }
            else{
                low[node] = min(low[node], low[adjnode]);
            }
        }
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for(auto conn : connections){
            int u=conn[0];
            int v=conn[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        vector<int> tin(n, 0);
        vector<int> low(n, 0);

        vector<vector<int>> bridges;

        dfs(0, vis, -1, adj, tin, low, bridges);

        return bridges;
    }
};