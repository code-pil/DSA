
// TC: E *(log V)

class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int s)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,s});
        vector<int> dist(V, 1e9);
        
        dist[s]=0;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            
            int v = it.second;
            int w = it.first;
            
            for(auto node : adj[v]){
                int adjnode = node[0];
                int weight = node[1];
                
                if(w + weight < dist[adjnode]){
                    dist[adjnode] = w + weight;
                    pq.push({dist[adjnode], adjnode});
                }
            }
        }
        
        return dist;
    }
};
