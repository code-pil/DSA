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

    bool isValidBST(TreeNode* node, long minVal, long maxVal){
        if(node == NULL) return true;

        if(minVal >= node->val or node->val >= maxVal) return false;

        return isValidBST(node->left, minVal, node->val) and
               isValidBST(node->right, node->val, maxVal);
    }

    bool isValidBST(TreeNode* root) {
        if(!root->left and !root->right) return true;
        return isValidBST(root, LONG_MIN, LONG_MAX);
    }
};