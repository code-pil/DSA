
//Left View
void lview(Node *root, int level, vector<int> &view){
    if(root == NULL) return;
    if(view.size() == level) view.push_back(root->data);
    lview(root->left, level+1, view);
    lview(root->right, level+1, view);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> leftview;
   lview(root, 0, leftview);
   return leftview;
}

//Right View

void rview(Node *root, int level, vector<int> &view){
    if(root == NULL) return;
    if(view.size() == level) view.push_back(root->data);
    lview(root->right, level+1, view);
    lview(root->left, level+1, view);
}

vector<int> rightView(Node *root)
{
   // Your code here
   vector<int> rightview;
   lview(root, 0, rightview);
   return rightview;
}
