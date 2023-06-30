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

class BSTIterator{
    stack<TreeNode*> st;
    // reverse -> true -> before iterator
    // reverse -> false -> next iterator
    bool reverse = true;
public:

    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    int next(){
        TreeNode* node = st.top();
        st.pop();
        if(reverse) pushAll(node->left);
        else pushAll(node->right);
        return node->val;
    }

    void pushAll(TreeNode* node){
        while(node){
            st.push(node);
            if(reverse){
                node = node->right;
            }
            else{
                node = node->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;

        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i+j==k) return true;
            if(i+j<k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};