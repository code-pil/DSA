class Solution {
public:

    bool check(int start, vector<vector<int>> &graph, vector<int> &col){
        queue<int> q;
        q.push(start);
        col[start]=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto adjnode : graph[node]){
                if(col[adjnode] == -1){
                    q.push(adjnode);
                    col[adjnode]=!col[node];
                }
                else if(col[adjnode] == col[node]) return false;
            }
        }
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> col(graph.size(),-1);
        for(int i=0;i<graph.size();i++){
            if(col[i]==-1){
                if(check(i, graph, col) == false) return false;
            }
        }
        return true;
    }
};