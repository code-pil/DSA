class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                col[i]=0;
                if(dfs(i, graph, col) == false) return false;
            }
        }
        return true;
    }

    bool dfs(int start, vector<vector<int>> &graph, vector<int> &col){
        for(auto adjnode : graph[start]){
            if(col[adjnode] == -1){
                col[adjnode] = !col[start];
                if(dfs(adjnode, graph, col) == false) return false;
            }
            else if(col[adjnode] == col[start]) return false;
        }
        return true;
    }
};