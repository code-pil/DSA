/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*> &m){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *parent = q.front();
            q.pop();
            if(parent->left){
                m[parent->left] = parent;
                q.push(parent->left);
            }
            if(parent->right){
                m[parent->right] = parent;
                q.push(parent->right);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*, TreeNode*> parents;
        markParents(root, parents);
        queue<TreeNode*> q;
        unordered_map<TreeNode*, int> visited;
        q.push(target);
        int dis=0;
        vector<int> ans;
        visited[target] = 1;
        while(dis != k+1){
            if(dis<k){
                int size = q.size();
                for(int i=0;i<size;i++){
                    TreeNode* temp = q.front();
                    q.pop();
                    if(!visited[temp->left] and temp->left){
                        q.push(temp->left);
                        visited[temp->left] = 1;
                    }
                    if(!visited[temp->right] and temp->right){
                        q.push(temp->right);
                        visited[temp->right] = 1;
                    }
                    if(!visited[parents[temp]] and parents[temp]){
                        q.push(parents[temp]);
                        visited[parents[temp]] = 1;
                    }
                }
                dis += 1;
            }
            else{
                int size = q.size();
                for(int i=0;i<size;i++){
                    TreeNode* node = q.front();
                    ans.push_back(node->val);
                    q.pop();
                }
                dis+=1;
            }
        }
        return ans;
    }
};