/*

Codestudio:: https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723?topList=striver-sde-sheet-problems&utm_source=striver&utm_medium=website&leftPanelTab=0

*/

void changeTree(BinaryTreeNode<int> *root){
    if(root == NULL) return;

    int child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(child < root->data){
        if(root->left) root->left->data = root->data;
        if(root->right) root->right->data = root->data;
    }
    else root->data = child;

    changeTree(root->left);
    changeTree(root->right);

    child = 0;
    if(root->left) child += root->left->data;
    if(root->right) child += root->right->data;

    if(root->left or root->right) root->data = child;

    return;

}