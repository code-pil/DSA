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

//For kth largest first find total total nodes = n one iteration by recusion or morris
// then after find n-k+1 smallest = kth largest

// kth smallest 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int ans;
        while(root){
            if(!root->left){
                k--;
                if(k==0) ans=root->val;
                root=root->right;
            }
            else{
                TreeNode* lastRight = root->left;
                while(lastRight->right and lastRight->right != root) lastRight = lastRight->right;

                if(lastRight->right){
                    k--;
                    if(k==0) ans=root->val;
                    lastRight->right = NULL;
                    root = root->right;
                }
                else{
                    lastRight->right = root;
                    root = root->left;
                }
            }
        }
        return ans;
    }
};