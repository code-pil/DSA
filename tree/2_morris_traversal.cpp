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

//Morris Inorder
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        TreeNode* cur=root, *prev=NULL;
        vector<int> inorder;
        while(cur!=NULL){
            if(cur->left==NULL){
                inorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* pred = cur->left;
                while(pred->right and pred->right != cur){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    pred->right = cur;
                    cur=cur->left;
                }
                else{
                    pred->right = NULL;
                    inorder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        return inorder;
    }
};

//Morris Preorder
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* cur = root;
        vector<int> preorder;

        while(cur!=NULL){
            if(cur->left == NULL){
                preorder.push_back(cur->val);
                cur = cur->right;
            }
            else{
                TreeNode* pred = cur->left;
                while(pred->right and pred->right != cur){
                    pred = pred->right;
                }
                if(pred->right == NULL){
                    preorder.push_back(cur->val);
                    pred->right = cur;
                    cur = cur->left;
                }
                else{
                    cur = cur->right;
                    pred->right = NULL;
                }
            }
        }
        return preorder;
    }
};