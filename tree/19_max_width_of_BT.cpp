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
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()){
            int size = q.size();
            long long minn = q.front().second;
            int first, last;
            for(int i=0;i<size;i++){
                TreeNode* node = q.front().first;
                long long id = q.front().second - minn;
                q.pop();
                if(i==0) first = id;
                if(i==size-1) last = id;
                if(node->left) q.push({node->left, 2*id+1});
                if(node->right) q.push({node->right, 2*id+2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};