//TC: E logE
//SC: E

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        // {wt, node, parent}
        // parent to store MST edges
        pq.push({0,0,-1});
        vector<int> vis(V, 0);
        
        int sum=0;
        
        while(!pq.empty()){
            int wt = pq.top()[0];
            int node = pq.top()[1];
            int parent = pq.top()[2];
            pq.pop();
            
            if(vis[node]) continue;
            vis[node]=1;
            sum+= wt;
            
            for(auto it : adj[node]){
                int adjnode = it[0];
                int weight = it[1];
                
                if(!vis[adjnode])
                    pq.push({weight, adjnode, node});
            }
        }
        
        return sum;
        
    }
};

