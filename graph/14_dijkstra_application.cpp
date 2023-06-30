// Leetcode: https://leetcode.com/problems/path-with-maximum-probability/description/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int, double>> adj[n+1];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        priority_queue<pair<double, int>> pq;
        vector<double> probability(n, 0);
        pq.push({1, start});

        while(!pq.empty()){
            auto [prob, node] = pq.top();
            pq.pop();

            for(auto [adjnode, p] : adj[node]){
                if(p*prob > probability[adjnode]){
                    probability[adjnode] = p*prob;
                    pq.push({probability[adjnode], adjnode});
                }
            }
        }

        return probability[end];
    }
};