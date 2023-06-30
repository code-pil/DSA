class Solution {
    
private:
    int timer=1;
    void dfs(int node, int parent, vector<int> adj[], vector<int> &vis, vector<int> &tin, 
    vector<int> &low, vector<int> &mark){
        
        vis[node]=1;
        tin[node]=low[node]=timer;
        timer++;
        int child=0;
        for(auto adjnode : adj[node]){
            if(not vis[adjnode]){
                child++;
                dfs(adjnode, node, adj, vis, tin, low, mark);
                low[node] = min(low[node], low[adjnode]);
                
                if(low[adjnode] >= tin[node] and parent!=-1){
                    mark[node]=1;
                }
            }
            else{
                low[node] = min(low[node], tin[adjnode]);
            }
        }
        
        if(parent == -1 and child>1) mark[node]=1;
        
    }
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        vector<int> vis(V, 0);
        vector<int> tin(V, 0);
        vector<int> low(V, 0);
        
        vector<int> mark(V, 0);
        for(int i=0;i<V;i++){
            if(not vis[i]){
                dfs(i, -1, adj, vis, tin, low, mark);
            }
        }
        
        vector<int> ans;
        for(int i=0;i<V;i++){
            if(mark[i]) ans.push_back(i);
        }
        
        if(ans.size()==0) return {-1};
        
        return ans;
    }
};