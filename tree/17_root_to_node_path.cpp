/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


bool findPath(TreeNode* root, int target, vector<int> &path){
    if(root==NULL) return false;
    
    path.push_back(root->val);
    
    if(root->val == target) {
        return true;
    }
    if(findPath(root->left, target, path) or findPath(root->right, target, path)) return true;
    
    path.pop_back();
    
    return false;
    
}
 
vector<int> Solution::solve(TreeNode* root, int B) {
    vector<int> path;
    bool res = findPath(root, B, path);
    return path;
}
