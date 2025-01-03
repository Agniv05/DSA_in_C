Node * searchBST(node* root, int key){
  if (root->data==key){
    return root;
  }
  else if (key>root->data){
    return searchBST(root->right,key);
  }
  else if (key<root->data){
    return searchBST(root->left,key);
  }
}
