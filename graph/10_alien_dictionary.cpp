//GFG: https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary

class Solution{
    public:
    string findOrder(string dict[], int N, int k) {
        //code here
        vector<int> adj[k];
        vector<int> indeg(k,0);
        for(int i=0;i<N-1;i++){
            string a = dict[i];
            string b = dict[i+1];
            int sz = min(a.length(), b.length());
     
            for(int j=0;j<sz;j++){
                if(a[j] != b[j]){
                    adj[a[j]-'a'].push_back(b[j]-'a');
                    indeg[b[j]-'a']++;
                    break;
                }
            }
        }
        
        queue<int> q;
        for(int i=0;i<k;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        string order;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            order += (node+'a');
            for(int adjnode : adj[node]){
                indeg[adjnode]--;
                if(indeg[adjnode]==0) q.push(adjnode);
            }
        }
        return order;
    }
};