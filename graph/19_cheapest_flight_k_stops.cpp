// Leetcode: https://leetcode.com/problems/cheapest-flights-within-k-stops/description/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        for(auto it : flights){
            adj[it[0]].push_back({it[1], it[2]});
        }

        vector<int> dist(n, 1e9);
        dist[src]=0;

        queue<vector<int>> pq;
        pq.push({0, src, 0});

        while(!pq.empty()){
            auto it = pq.front();
            int stops = it[0];
            int node = it[1];
            int cost = it[2];
            pq.pop();

            if(stops>k) continue;

            for(auto [adjnode, price] : adj[node]){
                if(stops<=k and cost + price < dist[adjnode]){
                    dist[adjnode] = cost + price;
                    pq.push({stops+1, adjnode, dist[adjnode]});
                }
            }
        }

        return dist[dst]==1e9?-1:dist[dst];
    }
};