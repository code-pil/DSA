//TC: 

class DisjointSet{
    vector<int> rank, parent, size;
public:
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1, 0);
        size.resize(n+1, 1);
        for(int i=1;i<=n;i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(rank[pu] > rank[pv]) parent[pv] = pu;
        else if(rank[pu] < rank[pv]) parent[pu] = pv;
        else parent[pu] = pv, rank[pv]++;
    }

    void unionBySize(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        if(pu == pv) return;

        if(size[pu] > size[pv]) parent[pv] = pu, size[pu] += size[pv];
        else parent[pu] = pv, size[pv] += size[pu];
    }
};


class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        // O(E)
        vector<vector<int>> edges;
        // O(V + E)
        for(int i=0;i<V;i++){
            for(auto it : adj[i]){
                int adjnode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt, adjnode, node});
            }
        }
        
        int sum=0;
        
        DisjointSet ds(V+1);
        // E log E
        sort(edges.begin(), edges.end());
        
        // E * 4 * alpha * 2
        for(auto edge : edges){
            int wt = edge[0];
            int v = edge[1];
            int u = edge[2];
            

            if(ds.findParent(u) != ds.findParent(v)){
                sum += wt;
                ds.unionByRank(u, v);
            }
        }
        
        return sum;
    }
};