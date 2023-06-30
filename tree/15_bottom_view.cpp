class Solution {
  public:
    vector <int> bottomView(Node *root) {
        // Your Code Here
        map<int,int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int verticalLine = temp.second;
            Node* node = temp.first;
            
            m[verticalLine] = node->data;
            
            if(node->left) q.push({node->left, verticalLine-1});
            if(node->right) q.push({node->right, verticalLine+1});
            
        }
        vector<int> ans;
        for(auto ele : m){
            ans.push_back(ele.second);
        }
        return ans;
    }
};