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

    void inOrder(TreeNode* root, vector<int> &inorder){
        if(root == NULL) return;
        inOrder(root->left,inorder);
        inorder.push_back(root->val);
        inOrder(root->right,inorder);
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inOrder(root, inorder);
        return inorder;
    }
};

class Solution {
public:

    void preOrder(TreeNode* root, vector<int> &preorder){
        if(root==NULL) return;
        preorder.push_back(root->val);
        preOrder(root->left, preorder);
        preOrder(root->right, preorder);
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        preOrder(root, preorder);
        return preorder;
    }
};

class Solution {
public:

    void postOrder(TreeNode* root, vector<int> &postorder){
        if(root==NULL) return;
        postOrder(root->left, postorder);
        postOrder(root->right, postorder);
        postorder.push_back(root->val);
    }

    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postOrder(root, postorder);
        return postorder;
    }
};