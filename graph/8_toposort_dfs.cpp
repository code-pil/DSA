class Solution
{
    
    void dfs(int node, int vis[], vector<int> adj[], stack<int> &st){
        vis[node]=1;
        for(auto adjnode : adj[node]){
            if(!vis[adjnode]) dfs(adjnode, vis, adj, st);
        }
        st.push(node);
    }
    
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V]={0};
	    stack<int> st;
	    for(int i=0;i<V;i++){
	        if(!vis[i]) dfs(i, vis, adj, st);
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};