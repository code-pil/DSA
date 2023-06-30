#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/

bool isLeaf(TreeNode<int> * root) {
  return !root -> left && !root -> right;
}

void addLeftBoundry(TreeNode<int>* root, vector<int> &v){
    TreeNode<int> *cur = root->left;
    while(cur){
        if(!isLeaf(cur)) v.push_back(cur->data);
        if(cur->left != NULL) cur = cur->left;
        else cur = cur->right;
    }
}

void addLeaves(TreeNode<int> *root, vector<int> &v){
    if(isLeaf(root)){
        v.push_back(root->data);
        return;
    }
    if(root->left != NULL) addLeaves(root->left, v);
    if(root->right != NULL) addLeaves(root->right, v);
}

void addRightBoundry(TreeNode<int> *root, vector<int> &v){
    vector<int> res;
    TreeNode<int> *cur = root->right;
    while(cur){
        if(!isLeaf(cur)) res.push_back(cur->data);
        if(cur->right != NULL) cur = cur->right;
        else cur = cur->left;
    }
    int sz = res.size();
    for(int i=sz-1;i>=0;i--){
        v.push_back(res[i]);
    }
}

vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if(root==NULL) return ans;
    if(!isLeaf(root)) ans.push_back(root->data);
    addLeftBoundry(root, ans);
    addLeaves(root, ans);
    addRightBoundry(root, ans);
    return ans;
}