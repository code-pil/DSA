//TC : O(N+2E)
//SC : O(N)

class Solution {
  public:
  
    bool detect(int node, int parent, vector<int> &vis, vector<int> adj[]){
        vis[node]=1;
        
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                if(detect(adjnode, node, vis, adj)) return true;
            }
            else if(adjnode != parent) return true;
        }
        return false;
    }
  
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V);
        for(int i=0;i<V;i++){
            if(!vis[i]){
                if(detect(i, -1, vis, adj)) return true;
            }
        }
        return false;
    }
};