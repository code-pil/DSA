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
 *
 */
//This is O(N) solution 
//Another solution is O(N^2) find height for every node seperately and check forevery node
class Solution {
public:

    int check(TreeNode* root){
        if(root==NULL) return 0;
        int leftHeight = check(root->left);
        int rightHeight = check(root->right);

        if(leftHeight == -1 || rightHeight == -1) return -1;
        if(abs(leftHeight - rightHeight) > 1) return -1;

        return 1+max(leftHeight, rightHeight);
    }

    bool isBalanced(TreeNode* root) {
        if(check(root) == -1) return false;
        return true;
    }
};
