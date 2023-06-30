class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int,int>> st;
        st.insert({0,S});
        vector<int> dist(V, 1e9);
        dist[S]=0;
        
        while(!st.empty()){
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);
            
            for(auto it : adj[node]){
                int weight = it[1];
                int adjnode = it[0];
                
                if(weight + dis < dist[adjnode]){
                    
                    if(dist[adjnode] != 1e9){
                        st.erase({dist[adjnode], adjnode});
                    }
                    
                    dist[adjnode] = weight + dis;
                    st.insert({dist[adjnode], adjnode});
                    
                }
            }
            
        }
        return dist;
    }
};