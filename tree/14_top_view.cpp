
//Concept of vertical order traversal

class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //Your code here
        map<int,int> m;
        queue<pair<Node*, int>> q;
        q.push({root, 0});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            
            int verticalLine = temp.second;
            Node* node = temp.first;
            if(m.find(verticalLine) == m.end()) m[verticalLine] = node->data;
            
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
