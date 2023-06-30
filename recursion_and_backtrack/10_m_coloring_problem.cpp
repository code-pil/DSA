class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isSafe(bool graph[101][101], int node, int col, vector<int> color, int n){
        for(int i=0;i<n;i++){
            if(i != node && graph[i][node] == 1 && color[i] == col) return false;
        }
        return true;
    }
    
    bool solve(bool graph[101][101], int m, int n, int node, vector<int> &color){
        if(node == n){
            return true;
        }
        
        for(int i=1; i<=m; i++){
            if(isSafe(graph, node, i, color, n)){
                color[node] = i;
                if(solve(graph, m, n, node+1, color)) return true;
                color[node] = 0;
            }
        }
        
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        // your code here
        vector<int> color(n);
        return solve(graph, m, n, 0, color);
    }
};
