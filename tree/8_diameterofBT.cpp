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

    pair<int,int> d(TreeNode* root){
        if(root==NULL) return {0,0};
        auto x = d(root->left);
        auto y = d(root->right);
        int rootLeftDiameter = x.second;
        int rootRightDiameter = y.second;
        int l = x.first;
        int r = y.first;
        int diameter = max(l+r, max(rootLeftDiameter, rootRightDiameter));
        return {1+max(l,r), diameter};

    }

    int diameterOfBinaryTree(TreeNode* root) {
        return d(root).second;
    }
};

//Another one
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }

private:
    int height(TreeNode* node, int& diameter) {

        if (!node) {
            return 0;
        }

        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);

        diameter = max(diameter, lh + rh);

        return 1 + max(lh, rh);
    }
};