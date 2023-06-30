
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indeg[V]={0};
	    for(int i=0;i<V;i++){
	        for(auto adjnode : adj[i]) indeg[adjnode]++;
	    }
	    
	    queue<int> q;
	    for(int i=0;i<V;i++){
	        if(indeg[i]==0) q.push(i);
	    }
	    
	    vector<int> toposo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        toposo.push_back(node);
	        for(int adjnode : adj[node]){
	            indeg[adjnode]--;
	            if(indeg[adjnode]==0) q.push(adjnode);
	        }
	    }
	    return toposo;
	}
};