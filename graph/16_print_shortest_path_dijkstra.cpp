// GFG: https://practice.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-weighted-undirected-graph

class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        
        for(auto edge : edges){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        vector<int> dist(n+1, 1e9);
        vector<int> parent(n+1);
        
        for(int i=0;i<=n;i++) parent[i]=i;
        
        pq.push({0, 1});
        dist[1]=0;
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjnode = it.first;
                int weight = it.second;
                
                if(weight + dis < dist[adjnode]){
                    dist[adjnode] = weight + dis;
                    pq.push({dist[adjnode], adjnode});
                    parent[adjnode] = node;
                }
                
            }
        }
        
        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
        }
        
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};