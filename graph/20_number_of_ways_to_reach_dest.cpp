//GFG: https://practice.geeksforgeeks.org/problems/number-of-ways-to-arrive-at-destination/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=/number-of-ways-to-arrive-at-destination

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        int mod = 1e9+7;
        vector<pair<int,int>> adj[n];
        for(auto road : roads){
            adj[road[0]].push_back({road[1], road[2]});
            adj[road[1]].push_back({road[0], road[2]});
        }
        
        vector<long long> dist(n, LONG_MAX);
        vector<long long> ways(n, 0);
        dist[0]=0;
        ways[0]=1;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, 0});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it : adj[node]){
                int weight = it.second;
                int adjnode = it.first;
                if(dis*1LL + weight < dist[adjnode]){
                    dist[adjnode] = dis*1LL + weight;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                }
                else if(dis + weight == dist[adjnode]){
                    ways[adjnode] = (ways[adjnode]*1LL + ways[node]);
                }
            }
        }
        
        return ways[n-1]%mod;
    }
};
