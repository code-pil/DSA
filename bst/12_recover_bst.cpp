//Leetcode: https://leetcode.com/problems/recover-binary-search-tree/description/

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
    TreeNode* prev = new TreeNode(INT_MIN);
    TreeNode* first = NULL, *last = NULL, *middle = NULL;
public:

    void recover(TreeNode* root){
        if(root==NULL) return;

        recover(root->left);

        if(prev->val > root->val){
            if(!first){
                first = prev;
                middle = root;
            }
            else last = root;
        }
        prev = root;

        recover(root->right);
    }

    void recoverTree(TreeNode* root) {
        recover(root);
        if(first and last)
            swap(first->val, last->val);
        else 
            swap(first->val, middle->val);
    }
};