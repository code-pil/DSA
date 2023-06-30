// GFG

class Solution
{
public:

    void dfs(int node, vector<int> &vis, vector<vector<int>> &adj, stack<int> &st){
        
        vis[node]=1;
        
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs(adjnode, vis, adj, st);
            }
        }
        
        st.push(node);
    }
    void dfs1(int node, vector<int> &vis, vector<int> adj[]){
        
        vis[node]=1;
        
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]){
                dfs1(adjnode, vis, adj);
            }
        }
        
    }

	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        //O(2*V)
        vector<int> vis(V, 0);
        stack<int> st;
        //V+E
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i, vis, adj, st);
            }
        }
        
        //O(V+E)
        vector<int> adjT[V];
        //V+E
        for(int i=0;i<V;i++){
            vis[i]=0;
            for(auto adjnode : adj[i]){
                adjT[adjnode].push_back(i);
            }
        }
        
        int scc=0;
        //(V+E)
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs1(node, vis, adjT);
            }
            
        }
        return scc;
    }
};