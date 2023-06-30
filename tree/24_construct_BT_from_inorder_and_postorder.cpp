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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(postorder, 0, postorder.size()-1, inorder, 0, inorder.size()-1, inMap);

        return root;
    }

    TreeNode* buildTree(vector<int> &postorder, int postStart, int postEnd,
                        vector<int> &inorder, int inStart, int inEnd, 
                        unordered_map<int,int> &inMap){
        
        if(postStart > postEnd or inStart > inEnd){
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[postEnd]);

        int inRoot = inMap[root->val];
        int numLeft = inRoot - inStart;

        root->left = buildTree(postorder, postStart, postStart+numLeft-1, inorder, inStart, inRoot-1, inMap);

        root->right = buildTree(postorder, postStart+numLeft, postEnd-1, inorder, inRoot+1, inEnd, inMap);

        return root;

    }
};