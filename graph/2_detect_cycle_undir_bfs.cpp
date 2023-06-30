// TC: O(N + 2*E)
// SC: O(N)

class Solution {
  public:
  
    bool detect(int src, vector<int> &visited, vector<int> adj[]){
        queue<pair<int,int>> q;
        q.push({src,-1});
        
        while(!q.empty()){
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            visited[node]=1;

            for(auto adjnode : adj[node]){
                if(!visited[adjnode]){
                    q.push({adjnode, node});
                }
                else if(adjnode != parent) return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> visited(V);
        bool isCycle = false;
        for(int i=0;i<V;i++){
            if(!visited[i]){
                isCycle |= detect(i, visited, adj);
            }
        }
        return isCycle;
    }
};