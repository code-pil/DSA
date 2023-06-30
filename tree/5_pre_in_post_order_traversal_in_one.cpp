#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/

vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    stack<pair<BinaryTreeNode<int>*, int>> st;
    st.push({root, 1});
    vector<vector<int>> ans(3);
    if(root == NULL) return ans;

    while(!st.empty()){
        auto temp = st.top();
        st.pop();
        if(temp.second == 1){
            ans[1].push_back(temp.first->data);
            temp.second++;
            st.push(temp);

            if(temp.first->left != NULL){
                st.push({temp.first->left, 1});
            }
        }
        else if(temp.second == 2){
            ans[0].push_back(temp.first->data);
            temp.second++;
            st.push(temp);

            if(temp.first->right != NULL){
                st.push({temp.first->right, 1});
            }
        }
        else ans[2].push_back(temp.first->data);
    }
    return ans;
}