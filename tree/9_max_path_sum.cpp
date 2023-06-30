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

    int find(TreeNode* root, int &sum){
        if(root==NULL) return 0;
        int leftSum = max(find(root->left, sum),0);
        int rightSum = max(find(root->right, sum),0);

        sum = max(sum, root->val+leftSum+rightSum);

        return max(root->val+leftSum, root->val+rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        int x = find(root, sum);
        return sum;
    }
};