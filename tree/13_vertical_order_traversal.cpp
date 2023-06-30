/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// New vector method found
// v.insert(position, element or set or vector) like
// v.insert(v.end(), set.begin(), set.end())


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> m;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            TreeNode *node = temp.first;
            int x = temp.second.first;
            int y = temp.second.second;
            m[x][y].insert(node->val);

            if(node->left){
                q.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                q.push({node->right, {x+1, y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto [x,y] : m){
            vector<int> col;
            for(auto [level, set] : y){
                col.insert(col.end(), set.begin(), set.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};